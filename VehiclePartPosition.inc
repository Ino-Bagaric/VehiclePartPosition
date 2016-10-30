/*
---------------------------------------

	VehiclePartPosition	
	@author: Ino
	@version: 1.0.0
	@release: 30/10/2016
	@build: 1	
	@download: github.com/Ino42O/VehiclePartPosition

---------------------------------------

	Functions list:

		* GetXYZOfVehiclePart(vehicleid, part, &Float:x, &Float:y, &Float:z, Float:offset = 0.5);
 	


 	Changelog:

 		30-10-2016:
 			* Initial release
 		


 	Available types:
 		* VEHICLE_PART_RFTIRE
		* VEHICLE_PART_LFTIRE
		* VEHICLE_PART_RRTIRE
		* VEHICLE_PART_LRTIRE
		* VEHICLE_PART_HOOD
		* VEHICLE_PART_TRUNK

---------------------------------------
*/

#include <a_samp>


#define _INC_VEHPARTS


#define VEHICLE_PART_RFTIRE 	(1)
#define VEHICLE_PART_LFTIRE 	(2)
#define VEHICLE_PART_RRTIRE 	(3)
#define VEHICLE_PART_LRTIRE 	(4)
#define VEHICLE_PART_HOOD 		(5)
#define VEHICLE_PART_TRUNK 		(6)



stock GetXYZOfVehiclePart(vehicleid, part, &Float:x, &Float:y, &Float:z, Float:offset = 0.5)
{
	new Float:X, Float:Y, Float:Z, Float:A;
	GetVehiclePos(vehicleid, x, y, z);
    GetVehicleZAngle(vehicleid, A);

    switch(part)
    {
    	case VEHICLE_PART_RFTIRE: // Right Front tire
    	{
    		GetVehicleModelInfo(GetVehicleModel(vehicleid), VEHICLE_MODEL_INFO_WHEELSFRONT, X, Y, Z);

		    x += ( ( (X + offset) * floatsin( -A + 90.0, degrees ) ) + ( ( Y * floatsin( -A, degrees ) ) ) );
		    y += ( ( (X + offset) * floatcos( -A + 90.0, degrees ) ) + ( ( Y * floatcos( -A, degrees ) ) ) );
    	}
    	case VEHICLE_PART_LFTIRE: // Left Front tire
    	{
    		GetVehicleModelInfo(GetVehicleModel(vehicleid), VEHICLE_MODEL_INFO_WHEELSFRONT, X, Y, Z);

		    x += ( ( (X + offset) * floatsin( -A - 90.0, degrees ) ) + ( ( Y * floatsin( -A, degrees ) ) ) );
		    y += ( ( (X + offset) * floatcos( -A - 90.0, degrees ) ) + ( ( Y * floatcos( -A, degrees ) ) ) );
    	}
    	case VEHICLE_PART_RRTIRE: // Right Rear tire
    	{
    		GetVehicleModelInfo(GetVehicleModel(vehicleid), VEHICLE_MODEL_INFO_WHEELSREAR, X, Y, Z);

		    x += ( ( (X + offset) * floatsin( -A + 90.0, degrees ) ) + ( ( Y * floatsin( -A, degrees ) ) ) );
		    y += ( ( (X + offset) * floatcos( -A + 90.0, degrees ) ) + ( ( Y * floatcos( -A, degrees ) ) ) );
    	}
    	case VEHICLE_PART_LRTIRE: // Left Rear tire
    	{
    		GetVehicleModelInfo(GetVehicleModel(vehicleid), VEHICLE_MODEL_INFO_WHEELSREAR, X, Y, Z);

		    x += ( ( (X + offset) * floatsin( -A - 90.0, degrees ) ) + ( ( Y * floatsin( -A, degrees ) ) ) );
		    y += ( ( (X + offset) * floatcos( -A - 90.0, degrees ) ) + ( ( Y * floatcos( -A, degrees ) ) ) );
    	}
    	case VEHICLE_PART_HOOD: // In Front
    	{
    		GetVehicleModelInfo(GetVehicleModel(vehicleid), VEHICLE_MODEL_INFO_SIZE, X, Y, Z);

    		x += ( (Y / 2.0 + offset) * floatsin( -A, degrees ) );
   			y += ( (Y / 2.0 + offset) * floatcos( -A, degrees ) );
    	}
    	case VEHICLE_PART_TRUNK: // Behind
    	{
    		GetVehicleModelInfo(GetVehicleModel(vehicleid), VEHICLE_MODEL_INFO_SIZE, X, Y, Z);

    		x += ( (Y / 2.0 + offset) * floatsin( -A + 180, degrees ) );
   			y += ( (Y / 2.0 + offset) * floatcos( -A + 180, degrees ) );
    	}
    }
}