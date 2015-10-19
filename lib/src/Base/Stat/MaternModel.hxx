//                                               -*- C++ -*-
/**
 *
 *  Copyright 2005-2015 Airbus-EDF-IMACS-Phimeca
 *
 *  This library is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  along with this library.  If not, see <http://www.gnu.org/licenses/>.
 *
 */
#ifndef OPENTURNS_MATERNMODEL_HXX
#define OPENTURNS_MATERNMODEL_HXX

#include "StationaryCovarianceModel.hxx"

BEGIN_NAMESPACE_OPENTURNS

/**
 * @class MaternModel
 */

class OT_API MaternModel
  : public StationaryCovarianceModel
{

  CLASSNAME;

public:

  /** Constructor based on spatial dimension*/
  explicit MaternModel(const UnsignedInteger spatialDimension = 1);

  /** Parameters constructor */
  MaternModel(const UnsignedInteger spatialDimension,
              const NumericalScalar theta,
              const NumericalScalar nu);

  /** Virtual copy constructor */
  MaternModel * clone() const;

  /** Computation of the covariance function */
  using StationaryCovarianceModel::operator();
  CovarianceMatrix operator() (const NumericalPoint & tau) const;
  /** Gradient */
  virtual Matrix partialGradient(const NumericalPoint & s,
                                 const NumericalPoint & t) const;

  /** Parameters accessor */
  void setParameters(const NumericalPoint & parameters);
  NumericalPointWithDescription getParameters() const;

  /** String converter */
  String __repr__() const;

  /** String converter */
  String __str__(const String & offset = "") const;

  /** Method save() stores the object through the StorageManager */
  void save(Advocate & adv) const;

  /** Method load() reloads the object from the StorageManager */
  void load(Advocate & adv);

private:

  // The shape parameter
  NumericalScalar nu_;

  // The normalization factor
  NumericalScalar logNormalizationFactor_;

  // Scaling constant
  NumericalScalar sqrt2nuOverTheta_;

} ; /* class MaternModel */

END_NAMESPACE_OPENTURNS

#endif