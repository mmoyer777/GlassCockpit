/*=========================================================================

  OpenGC - The Open Source Glass Cockpit Project
  Please see our web site at http://www.opengc.org

  Albatross UAV Project - http://www.albatross-uav.org

  Copyright (c) 2006 Hugo Vincent
  All rights reserved.
  See Copyright.txt or http://www.opengc.org/Copyright.htm for details.

  This software is distributed WITHOUT ANY WARRANTY; without even 
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR 
  PURPOSE.  See the above copyright notice for more information.

  =========================================================================*/

#ifndef FlightCourse_h
#define FlightCourse_h

#include <vector>
#include "CoursePoint.h"

namespace OpenGC
{

class FlightCourse : public std::vector<CoursePoint>
{
public:
	FlightCourse();
	~FlightCourse();
};

} // end namespace OpenGC

#endif

