/*=========================================================================

  Copyright (c) 2005-2010 Hugo Vincent <hugo.vincent@gmail.com>
  All rights reserved.
  
  This project is distributed under the terms of the GNU General Public License
  Version 3 <http://www.gnu.org/licenses/gpl.html>.
  
      This program is free software: you can redistribute it and/or modify
      it under the terms of the GNU General Public License as published by
      the Free Software Foundation, specifically version 3 of the License.
  
      This program is distributed in the hope that it will be useful,
      but WITHOUT ANY WARRANTY; without even the implied warranty of
      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
      GNU General Public License for more details.
  
      You should have received a copy of the GNU General Public License
      along with this program.  If not, see <http://www.gnu.org/licenses/>.

=========================================================================*/

#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include "AirportList.h"
#include "AirportGeoObj.h"
#include "Constants.h"
#include "BinaryNavData.h"
#include "Debug.h"

namespace OpenGC
{

using namespace std;

AirportList::AirportList()
{

}

AirportList::~AirportList()
{

}

bool AirportList::LoadData(const string& fileName)
{
	ifstream file(fileName.c_str(), ios::binary);
	Assert(file.is_open(), "can't read airport database");

	// The struct that is read in for each airport
	BinaryNavData::AirportData *apt = new BinaryNavData::AirportData;

	// Now iterate over the structs in the file
	while (file.eof() != 1)
	{
		file.read((char*)apt, sizeof(BinaryNavData::AirportData));

		// Ensure ID string is null terminated
		if (apt->id_length >= MAX_APT_ID_LENGTH)
		{
			apt->id[MAX_APT_ID_LENGTH] = 0;
		}
		else
		{
			apt->id[apt->id_length] = 0;
		}
		
		// Create the AirportGeoObj and fill out it's fields
		AirportGeoObj* pAirport = new AirportGeoObj();
		pAirport->SetAltitudeMeters(apt->elev);
		pAirport->SetIdentification(apt->id);
		pAirport->SetDegreeLat(apt->lat);
		pAirport->SetDegreeLon(apt->lon);

		// Now add the airport to the list
		this->push_back(pAirport);
	}
	delete apt;
	return true;
}

} // end namespace OpenGC

