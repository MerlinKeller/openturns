#! /usr/bin/env python

from __future__ import print_function
from openturns import *
from math import *


def printNumericalPoint(point, digits):
    oss = "["
    eps = pow(0.1, digits)
    for i in range(point.getDimension()):
        if i == 0:
            sep = ""
        else:
            sep = ","
        if fabs(point[i]) < eps:
            oss += sep + '%.6f' % fabs(point[i])
        else:
            oss += sep + '%.6f' % point[i]
        sep = ","
    oss += "]"
    return oss


TESTPREAMBLE()

try:

    # We create a numerical math function
    # Analytical construction
    inputFunc = Description(2)
    inputFunc[0] = "x0"
    inputFunc[1] = "x1"
    outputFunc = Description(1)
    outputFunc[0] = "y0"
    formulas = Description(outputFunc.getSize())
    formulas[0] = "-(6+x0^2-x1)"
    print("formulas=", formulas)
    myFunction = NumericalMathFunction(inputFunc, outputFunc, formulas)

    dim = myFunction.getInputDimension()
    # We create a normal distribution point of dimension 1
    mean = NumericalPoint(dim, 0.0)
    # x0
    mean[0] = 5.0
    # x1
    mean[1] = 2.1
    sigma = NumericalPoint(dim, 0.0)
    # x0
    sigma[0] = 3.3
    # x1
    sigma[1] = 3.0
    R = CorrelationMatrix(dim)
    myDistribution = Normal(mean, sigma, R)

    # we name the components of the distribution
    componentDescription = Description(dim)
    componentDescription[0] = "Marginal 1"
    componentDescription[1] = "Marginal 2"
    myDistribution.setDescription(componentDescription)

    # We create a 'usual' RandomVector from the Distribution
    vect = RandomVector(myDistribution)

    # We create a composite random vector
    output = RandomVector(myFunction, vect)
    outputDescription = Description(1)
    outputDescription[0] = "Interest Variable 1"
    output.setDescription(outputDescription)

    # We create an Event from this RandomVector
    myEvent = Event(output, Greater(), 0.0)

    # We create a NearestPoint algorithm
    myCobyla = Cobyla()
    myCobyla.setMaximumIterationsNumber(200)
    myCobyla.setMaximumAbsoluteError(1.0e-10)
    myCobyla.setMaximumRelativeError(1.0e-10)
    myCobyla.setMaximumResidualError(1.0e-10)
    myCobyla.setMaximumConstraintError(1.0e-10)
    print("myCobyla=", myCobyla)

    # We create a FORM algorithm
    # The first parameter is an OptimizationSolver
    # The second parameter is an event
    # The third parameter is a starting point for the design point research
    myAlgo = FORM(myCobyla, myEvent, mean)

    print("FORM=", myAlgo)

    # Perform the simulation
    myAlgo.run()

    # Stream out the result
    result = FORMResult(myAlgo.getResult())
    digits = 5
    print("importance factors=", printNumericalPoint(
        result.getImportanceFactors(), digits))

    # Graph 1 : Importance Factors graph
    importanceFactorsGraph = result.drawImportanceFactors()
    importanceFactorsGraph.draw("ImportanceFactorsDrawingFORM", 640, 480)

    # Graph 2 : Hasofer Reliability Index Sensitivity Graphs graph
    reliabilityIndexSensitivityGraphs = result.drawHasoferReliabilityIndexSensitivity(
    )
    graph2a = reliabilityIndexSensitivityGraphs[0]
    graph2a.draw("HasoferReliabilityIndexMarginalSensitivityDrawing", 640, 480)
    # Check that the correct files have been generated by computing their
    # checksum
    graph2b = reliabilityIndexSensitivityGraphs[1]
    graph2b.draw("HasoferReliabilityIndexOtherSensitivityDrawing", 640, 480)
    # Check that the correct files have been generated by computing their
    # checksum

    # Graph 3 : FORM Event Probability Sensitivity Graphs graph
    eventProbabilitySensitivityGraphs = result.drawEventProbabilitySensitivity(
    )
    graph3a = eventProbabilitySensitivityGraphs[0]
    graph3a.draw("EventProbabilityIndexMarginalSensitivityDrawing", 640, 480)
    # Check that the correct files have been generated by computing their
    # checksum
    graph3b = eventProbabilitySensitivityGraphs[1]
    graph3b.draw("EventProbabilityIndexOtherSensitivityDrawing", 640, 480)
    # Check that the correct files have been generated by computing their
    # checksum

    # Graph 4 : Convergence history
    graph4 = result.getOptimizationResult().drawErrorHistory()
    graph4.draw("ConvergenceHistory", 640, 480)

except:
    import sys
    print("t_FORM_draw.py", sys.exc_info()[0], sys.exc_info()[1])