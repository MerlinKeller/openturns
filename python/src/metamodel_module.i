// SWIG file metamodel_module.i

%module(package="openturns", docstring="Meta-modelling.") metamodel
#pragma SWIG nowarn=302,509
//%feature("autodoc","1");

%{
#include "OTconfig.hxx"
#include "OTBase.hxx"
#include "OTModel.hxx"
#include "OTDistribution.hxx"
#include "OTWeightedExperiments.hxx"
#include "OTOrthogonalBasis.hxx"
#include "OTMetaModel.hxx"
%}

%include typemaps.i
%include OTtypes.i
%include OTexceptions.i
%include std_vector.i

%include BaseFuncCollection.i
%import base_module.i

/* Uncertainty/Model */
/* Uncertainty/Distribution */
%import model_copula_module.i
%import UncertaintyModelCopulaTemplateDefs.i
// KrigingResult::operator() returns Normal
%import Normal.i

/* Uncertainty/Algorithm/WeightedExperiment */
%import weightedexperiment_module.i

/* Uncertainty/Algorithm/OrthogonalBasis */
%import orthogonalbasis_module.i
%import UncertaintyOrthogonalBasisTemplateDefs.i

/* Uncertainty/Model */
%import randomvector_module.i

/* Uncertainty/Algorithm/Metamodel */
%include MetaModelResult.i
%include KrigingResult.i
%include MetaModelAlgorithm.i
%include LinearTaylor.i
%include QuadraticTaylor.i
%include LinearLeastSquares.i
%include QuadraticLeastSquares.i
%include AdaptiveStrategyImplementation.i
%include FixedStrategy.i
%include SequentialStrategy.i
%include CleaningStrategy.i
%include AdaptiveStrategy.i
%include ProjectionStrategyImplementation.i
%include LeastSquaresStrategy.i
%include IntegrationStrategy.i
%include ProjectionStrategy.i
%include FunctionalChaosResult.i
%include FunctionalChaosAlgorithm.i
%include KrigingAlgorithm.i
%include MetaModelValidation.i

/* Uncertainty/Model */
%include RandomVector.i
%include CompositeRandomVector.i
%include EventRandomVectorImplementation.i
%include EventDomainImplementation.i
%include EventProcess.i
%include ConditionalRandomVector.i
%include Event.i
%include StandardEvent.i

/* Uncertainty/Algorithm/Metamodel */
%include FunctionalChaosRandomVector.i
%include KrigingRandomVector.i

/* At last we include template definitions */
%include UncertaintyMetaModelTemplateDefs.i