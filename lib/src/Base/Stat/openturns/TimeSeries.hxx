//                                               -*- C++ -*-
/**
 *  @brief The class TimeSeries implements values indexed by time
 *
 *  Copyright 2005-2016 Airbus-EDF-IMACS-Phimeca
 *
 *  This library is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTCULAR PURPOSE.  See the
 *  GNU Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  along with this library.  If not, see <http://www.gnu.org/licenses/>.
 *
 */
#ifndef OPENTURNS_TIMESERIES_HXX
#define OPENTURNS_TIMESERIES_HXX

#include <stdint.h> // for uint64_t
#include <cmath>    // for nearbyint

#include "openturns/NumericalPoint.hxx"
#include "openturns/Description.hxx"
#include "openturns/Indices.hxx"
#include "openturns/PersistentCollection.hxx"
#include "openturns/Collection.hxx"
#include "openturns/NumericalSample.hxx"
#include "openturns/Graph.hxx"
#include "openturns/RegularGrid.hxx"
#include "openturns/FieldImplementation.hxx"
#include "openturns/Field.hxx"

BEGIN_NAMESPACE_OPENTURNS

/**
 * @class TimeSeries
 */

class OT_API TimeSeries
  : public FieldImplementation
{
  CLASSNAME;

public:

  /**
   * Default constructor
   */
  TimeSeries();

  /** Standard constructor */
  TimeSeries(const UnsignedInteger n,
             const UnsignedInteger dim);

  /** Constructor from a TimeGrid and a dimension */
  TimeSeries(const RegularGrid & tg,
             const UnsignedInteger dim);

  /** Constructor from a TimeGrid and a sample */
  TimeSeries(const RegularGrid & tg,
             const NumericalSample & sample);

  /** Constructor from a Field */
  TimeSeries(const Field & field);

#ifndef SWIG
  /** Constructor from a collection of NumericalPoint */
  TimeSeries(const Collection<NumericalPoint> & coll);
#endif

  /** Virtual constructor */
  TimeSeries * clone() const;

  /**
   * String converter
   * This method shows human readable information on the
   * internal state of an TimeSeries. It is used when streaming
   * the TimeSeries or for user information.
   */
  virtual String __repr__() const;
  virtual String __str__(const String & offset = "") const;

  Bool operator ==(const TimeSeries & other) const;

  /** Append an element to the collection */
  TimeSeries & add(const NumericalPoint & point);

  /** Append a sample to the collection */
  TimeSeries & add(const NumericalSample & sample);

  /** Append another time series to the collection. The time grids must match (one follows the other) */
  TimeSeries & add(const TimeSeries & continuer);

  /** Method save() stores the object through the StorageManager */
  virtual void save(Advocate & adv) const;

  /** Method load() reloads the object from the StorageManager */
  virtual void load(Advocate & adv);

private:

  /** The start time of the time series */
  NumericalScalar start_;

  /** The interval of the underlying regular time grid */
  NumericalScalar timeStep_;

  /** The number of timestamps of the underlying regular time grid */
  UnsignedInteger n_;

}; /* class TimeSeries */

END_NAMESPACE_OPENTURNS

#endif /* OPENTURNS_TIMESERIES_HXX */
