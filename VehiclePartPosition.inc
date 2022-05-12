/*
---------------------------------------

	VehiclePartPosition	
	@author: Ino / Walter-Correa
	@version: 2.0.0
	@release: 30/10/2016
	@build: 5	
	@download: github.com/Ino42O/VehiclePartPosition

---------------------------------------

	Functions list:

	* GetPosNearVehiclePart(vehicleid, part, &Float:x, &Float:y, &Float:z, Float:offset = 0.5); - To get the position in the world.
	* GetVehiclePartPos(vehicleid, part, &Float:x, &Float:y, &Float:z); - To get the position in the vehicle.
	* IsPlayerNearVehiclePart(playerid, vehicleid, part, Float:radius = 1.0, Float:offset = 0.0); - Check if the player is near of a vehicle part.
	* SetPlayerNearVehiclePart(playerid, vehicleid, part, Float:offset = 0.5); - Teleports a player to the front of a part of the vehicle.
	* GetVehiclePartName(part); - Return the vehicle part name.
 	


 	Changelog:

	03-05-2022
	* Add support for sampctl

 	30-10-2016:
 	* Initial release

	31-10-2016:
        * Support ColAndreas to get more informations if vehicle is not on flat ground
	
	27-09-2020:
        * Added new vehicle parts
	* General code improvements
	* Renamed GetXYZOfVehiclePart to GetPosNearVehiclePart
	* Added GetVehiclePartPos
	
	29-09-2020:
	* Added IsPlayerNearVehiclePart
	* Added SetPlayerNearVehiclePart
	* Added GetVehiclePartName
	
	27/10/2021:
	* Added new vehicle parts 
 		


 	Available part types:
	
 	* VEH_PART_FTIRE - Front Tire - Bikes
 	* VEH_PART_RTIRE - Rear Tire - Bikes
 	* VEH_PART_RFTIRE - Right Front Tire
 	* VEH_PART_LFTIRE - Left Front Tire
 	* VEH_PART_RRTIRE - Right Rear Tire
 	* VEH_PART_LRTIRE - Left Rear Tire
 	* VEH_PART_RMTIRE - Right Mid Tire
 	* VEH_PART_LMTIRE - Left Mid Tire
	* VEH_PART_RFSEAT - Right Front Seat
	* VEH_PART_LFSEAT - Left Front Seat
	* VEH_PART_RRSEAT - Right Rear Seat
	* VEH_PART_LRSEAT - Left Rear Seat
 	* VEH_PART_HOOD - Hood
 	* VEH_PART_TRUNK - Trunk
 	* VEH_PART_PCAP - Petrol Cap

---------------------------------------
*/

#include <a_samp>


#define _INC_VEHPARTS

#define VEH_PART_FTIRE 1
#define VEH_PART_RTIRE 2
#define VEH_PART_RFTIRE 3
#define VEH_PART_LFTIRE 4
#define VEH_PART_RRTIRE 5
#define VEH_PART_LRTIRE 6
#define VEH_PART_RMTIRE 7
#define VEH_PART_LMTIRE 8
#define VEH_PART_RFSEAT 9
#define VEH_PART_LFSEAT 10
#define VEH_PART_RRSEAT 11
#define VEH_PART_LRSEAT 12
#define VEH_PART_HOOD 13
#define VEH_PART_TRUNK 14
#define VEH_PART_PCAP 15

stock GetPosNearVehiclePart(vehicleid, part, &Float:x, &Float:y, &Float:z, Float:offset = 0.5)
{
	#if defined COLANDREAS
	new Float:cz;
	#endif

	new Float:X,Float:Y,Float:Z,Float:A;
	GetVehiclePos(vehicleid, x, y, z);
	GetVehicleZAngle(vehicleid, A);

	switch(part)
	{
		case VEH_PART_FTIRE://Front Tire
		{
			GetVehicleModelInfo(GetVehicleModel(vehicleid), VEHICLE_MODEL_INFO_WHEELSFRONT, X, Y, Z);
			x += (X+offset)*floatsin(-A,degrees) + (Y*floatsin(-A,degrees));
			y += (X+offset)*floatcos(-A,degrees) + (Y*floatcos(-A,degrees));
		}
		case VEH_PART_RTIRE://Rear Tire
		{
			GetVehicleModelInfo(GetVehicleModel(vehicleid), VEHICLE_MODEL_INFO_WHEELSREAR, X, Y, Z);
			x += (X+offset)*floatsin(-A+180.0,degrees) + (Y*floatsin(-A,degrees));
			y += (X+offset)*floatcos(-A+180.0,degrees) + (Y*floatcos(-A,degrees));
		}
		case VEH_PART_RFTIRE://Right Front Tire
		{
			GetVehicleModelInfo(GetVehicleModel(vehicleid), VEHICLE_MODEL_INFO_WHEELSFRONT, X, Y, Z);
			x += (X+offset)*floatsin(-A+90.0,degrees) + (Y*floatsin(-A,degrees));
			y += (X+offset)*floatcos(-A+90.0,degrees) + (Y*floatcos(-A,degrees));
		}
		case VEH_PART_LFTIRE://Left Front Tire
		{
			GetVehicleModelInfo(GetVehicleModel(vehicleid), VEHICLE_MODEL_INFO_WHEELSFRONT, X, Y, Z);
			x += (X+offset)*floatsin(-A-90.0,degrees) + (Y*floatsin(-A,degrees));
			y += (X+offset)*floatcos(-A-90.0,degrees) + (Y*floatcos(-A,degrees));
		}
		case VEH_PART_RRTIRE://Right Rear Tire
		{
			GetVehicleModelInfo(GetVehicleModel(vehicleid), VEHICLE_MODEL_INFO_WHEELSREAR, X, Y, Z);
			x += (X+offset)*floatsin(-A+90.0,degrees) + (Y*floatsin(-A,degrees));
			y += (X+offset)*floatcos(-A+90.0,degrees) + (Y*floatcos(-A,degrees));
		}
		case VEH_PART_LRTIRE://Left Rear Tire
		{
			GetVehicleModelInfo(GetVehicleModel(vehicleid), VEHICLE_MODEL_INFO_WHEELSREAR, X, Y, Z);
			x += (X+offset)*floatsin(-A-90.0,degrees) + (Y*floatsin(-A,degrees));
			y += (X+offset)*floatcos(-A-90.0,degrees) + (Y*floatcos(-A,degrees));
		}
		case VEH_PART_RMTIRE://Right Mid Tire
		{
			GetVehicleModelInfo(GetVehicleModel(vehicleid), VEHICLE_MODEL_INFO_WHEELSMID, X, Y, Z);
			x += (X+offset)*floatsin(-A+90.0,degrees) + (Y*floatsin(-A,degrees));
			y += (X+offset)*floatcos(-A+90.0,degrees) + (Y*floatcos(-A,degrees));
		}
		case VEH_PART_LMTIRE://Left Mid Tire
		{
			GetVehicleModelInfo(GetVehicleModel(vehicleid), VEHICLE_MODEL_INFO_WHEELSMID, X, Y, Z);
			x += (X+offset)*floatsin(-A-90.0,degrees) + (Y*floatsin(-A,degrees));
			y += (X+offset)*floatcos(-A-90.0,degrees) + (Y*floatcos(-A,degrees));
		}
		case VEH_PART_RFSEAT://Right Front Seat
		{
			GetVehicleModelInfo(GetVehicleModel(vehicleid), VEHICLE_MODEL_INFO_FRONTSEAT, X, Y, Z);
			x += (X+offset)*floatsin(-A+90.0,degrees) + (Y*floatsin(-A,degrees));
			y += (X+offset)*floatcos(-A+90.0,degrees) + (Y*floatcos(-A,degrees));
		}
		case VEH_PART_LFSEAT://Left Front Seat
		{
			GetVehicleModelInfo(GetVehicleModel(vehicleid), VEHICLE_MODEL_INFO_FRONTSEAT, X, Y, Z);
			x += (X+offset)*floatsin(-A-90.0,degrees) + (Y*floatsin(-A,degrees));
			y += (X+offset)*floatcos(-A-90.0,degrees) + (Y*floatcos(-A,degrees));
		}
		case VEH_PART_RRSEAT://Right Rear Seat
		{
			GetVehicleModelInfo(GetVehicleModel(vehicleid), VEHICLE_MODEL_INFO_REARSEAT, X, Y, Z);
			x += (X+offset)*floatsin(-A+90.0,degrees) + (Y*floatsin(-A,degrees));
			y += (X+offset)*floatcos(-A+90.0,degrees) + (Y*floatcos(-A,degrees));
		}
		case VEH_PART_LRSEAT://Left Rear Seat
		{
			GetVehicleModelInfo(GetVehicleModel(vehicleid), VEHICLE_MODEL_INFO_REARSEAT, X, Y, Z);
			x += (X+offset)*floatsin(-A-90.0,degrees) + (Y*floatsin(-A,degrees));
			y += (X+offset)*floatcos(-A-90.0,degrees) + (Y*floatcos(-A,degrees));
		}
		case VEH_PART_HOOD://In Front
		{
			GetVehicleModelInfo(GetVehicleModel(vehicleid), VEHICLE_MODEL_INFO_SIZE, X, Y, Z);
			x += (Y/2.0+offset) * floatsin(-A,degrees);
			y += (Y/2.0+offset) * floatcos(-A,degrees);
		}
		case VEH_PART_TRUNK://Behind
		{
			GetVehicleModelInfo(GetVehicleModel(vehicleid), VEHICLE_MODEL_INFO_SIZE, X, Y, Z);
			x += (Y/2.0+offset) * floatsin(-A+180,degrees);
			y += (Y/2.0+offset) * floatcos(-A+180,degrees);
		}
		case VEH_PART_PCAP:
		{
			GetVehicleModelInfo(GetVehicleModel(vehicleid), VEHICLE_MODEL_INFO_PETROLCAP, X, Y, Z);
			new cap = GetVehiclePetrolCapSide(vehicleid);
			if(cap == 0) Y -= 2.0;
			if(cap == 1) X += offset;
			if(cap == 2) X -= offset;
			if(cap == 3) Y -= offset;
			if(cap == 4) Y += offset+0.5;
			x = floatsin(360-A,degrees)*Y+floatcos(360-A,degrees)*X+x;
			y = floatcos(360-A,degrees)*Y-floatsin(360-A,degrees)*X+y;
			z += Z;
		}
	}
	#if defined COLANDREAS
	CA_RayCastLine(x, y, z, x, y, z + 5.0, cz, cz, cz);
	if (cz != 0.0) z = cz + offset;
	#endif
}

stock GetVehiclePartPos(vehicleid, part, &Float:x, &Float:y, &Float:z)
{
	new Float:X,Float:Y,Float:Z,Float:vx,
	Float:vy,Float:vz,Float:px,Float:py,Float:a;
	GetVehiclePos(vehicleid, vx, vy, vz);
	GetVehicleZAngle(vehicleid, a);

	switch(part)
	{
		case VEH_PART_FTIRE://Front Tire
		{
			GetVehicleModelInfo(GetVehicleModel(vehicleid), VEHICLE_MODEL_INFO_WHEELSFRONT, x, y, z);
		}
		case VEH_PART_RTIRE://Rear Tire
		{
			GetVehicleModelInfo(GetVehicleModel(vehicleid), VEHICLE_MODEL_INFO_WHEELSREAR, x, y, z);
		}
		case VEH_PART_RFTIRE://Right Front Tire
		{
			GetVehicleModelInfo(GetVehicleModel(vehicleid), VEHICLE_MODEL_INFO_WHEELSFRONT, X, Y, Z);
			px = vx, py = vy;
			px += (X*floatsin(-a+90.0,degrees)) + (Y*floatsin(-a,degrees));
			py += (X*floatcos(-a+90.0,degrees)) + (Y*floatcos(-a,degrees));
			x = (px-vx)*floatcos(a, degrees)+(py-vy)*floatsin(a, degrees);
			y = -(px-vx)*floatsin(a, degrees)+(py-vy)*floatcos(a, degrees);
			z = Z;
		}
		case VEH_PART_LFTIRE://Left Front Tire
		{
			GetVehicleModelInfo(GetVehicleModel(vehicleid), VEHICLE_MODEL_INFO_WHEELSFRONT, X, Y, Z);
			px = vx, py = vy;
			px += (X*floatsin(-a-90.0,degrees)) + (Y*floatsin(-a,degrees));
			py += (X*floatcos(-a-90.0,degrees)) + (Y*floatcos(-a,degrees));
			x = (px-vx)*floatcos(a, degrees)+(py-vy)*floatsin(a, degrees);
			y = -(px-vx)*floatsin(a, degrees)+(py-vy)*floatcos(a, degrees);
			z = Z;
		}
		case VEH_PART_RRTIRE://Right Rear Tire
		{
			GetVehicleModelInfo(GetVehicleModel(vehicleid), VEHICLE_MODEL_INFO_WHEELSREAR, X, Y, Z);
			px = vx, py = vy;
			px += (X*floatsin(-a+90.0,degrees)) + (Y*floatsin(-a,degrees));
			py += (X*floatcos(-a+90.0,degrees)) + (Y*floatcos(-a,degrees));
			x = (px-vx)*floatcos(a, degrees)+(py-vy)*floatsin(a, degrees);
			y = -(px-vx)*floatsin(a, degrees)+(py-vy)*floatcos(a, degrees);
			z = Z;
		}
		case VEH_PART_LRTIRE://Left Rear Tire
		{
			GetVehicleModelInfo(GetVehicleModel(vehicleid), VEHICLE_MODEL_INFO_WHEELSREAR, X, Y, Z);
			px = vx, py = vy;
			px += (X*floatsin(-a-90.0,degrees)) + (Y*floatsin(-a,degrees));
			py += (X*floatcos(-a-90.0,degrees)) + (Y*floatcos(-a,degrees));
			x = (px-vx)*floatcos(a, degrees)+(py-vy)*floatsin(a, degrees);
			y = -(px-vx)*floatsin(a, degrees)+(py-vy)*floatcos(a, degrees);
			z = Z;
		}
		case VEH_PART_RMTIRE://Right Mid Tire
		{
			GetVehicleModelInfo(GetVehicleModel(vehicleid), VEHICLE_MODEL_INFO_WHEELSMID, X, Y, Z);
			px = vx, py = vy;
			px += (X*floatsin(-a+90.0,degrees)) + (Y*floatsin(-a,degrees));
			py += (X*floatcos(-a+90.0,degrees)) + (Y*floatcos(-a,degrees));
			x = (px-vx)*floatcos(a, degrees)+(py-vy)*floatsin(a, degrees);
			y = -(px-vx)*floatsin(a, degrees)+(py-vy)*floatcos(a, degrees);
			z = Z;
		}
		case VEH_PART_LMTIRE://Left Mid Tire
		{
			GetVehicleModelInfo(GetVehicleModel(vehicleid), VEHICLE_MODEL_INFO_WHEELSMID, X, Y, Z);
			px = vx, py = vy;
			px += (X*floatsin(-a-90.0,degrees)) + (Y*floatsin(-a,degrees));
			py += (X*floatcos(-a-90.0,degrees)) + (Y*floatcos(-a,degrees));
			x = (px-vx)*floatcos(a, degrees)+(py-vy)*floatsin(a, degrees);
			y = -(px-vx)*floatsin(a, degrees)+(py-vy)*floatcos(a, degrees);
			z = Z;
		}
		case VEH_PART_RFSEAT://Right Front Seat
		{
			GetVehicleModelInfo(GetVehicleModel(vehicleid), VEHICLE_MODEL_INFO_FRONTSEAT, X, Y, Z);
			px = vx, py = vy;
			px += (X*floatsin(-a+90.0,degrees)) + (Y*floatsin(-a,degrees));
			py += (X*floatcos(-a+90.0,degrees)) + (Y*floatcos(-a,degrees));
			x = (px-vx)*floatcos(a, degrees)+(py-vy)*floatsin(a, degrees);
			y = -(px-vx)*floatsin(a, degrees)+(py-vy)*floatcos(a, degrees);
			z = Z;
		}
		case VEH_PART_LFSEAT://Left Front Seat
		{
			GetVehicleModelInfo(GetVehicleModel(vehicleid), VEHICLE_MODEL_INFO_FRONTSEAT, X, Y, Z);
			px = vx, py = vy;
			px += (X*floatsin(-a-90.0,degrees)) + (Y*floatsin(-a,degrees));
			py += (X*floatcos(-a-90.0,degrees)) + (Y*floatcos(-a,degrees));
			x = (px-vx)*floatcos(a, degrees)+(py-vy)*floatsin(a, degrees);
			y = -(px-vx)*floatsin(a, degrees)+(py-vy)*floatcos(a, degrees);
			z = Z;
		}
		case VEH_PART_RRSEAT://Right Rear Seat
		{
			GetVehicleModelInfo(GetVehicleModel(vehicleid), VEHICLE_MODEL_INFO_REARSEAT, X, Y, Z);
			px = vx, py = vy;
			px += (X*floatsin(-a+90.0,degrees)) + (Y*floatsin(-a,degrees));
			py += (X*floatcos(-a+90.0,degrees)) + (Y*floatcos(-a,degrees));
			x = (px-vx)*floatcos(a, degrees)+(py-vy)*floatsin(a, degrees);
			y = -(px-vx)*floatsin(a, degrees)+(py-vy)*floatcos(a, degrees);
			z = Z;
		}
		case VEH_PART_LRSEAT://Left Rear Seat
		{
			GetVehicleModelInfo(GetVehicleModel(vehicleid), VEHICLE_MODEL_INFO_REARSEAT, X, Y, Z);
			px = vx, py = vy;
			px += (X*floatsin(-a-90.0,degrees)) + (Y*floatsin(-a,degrees));
			py += (X*floatcos(-a-90.0,degrees)) + (Y*floatcos(-a,degrees));
			x = (px-vx)*floatcos(a, degrees)+(py-vy)*floatsin(a, degrees);
			y = -(px-vx)*floatsin(a, degrees)+(py-vy)*floatcos(a, degrees);
			z = Z;
		}
		case VEH_PART_HOOD://In Front
		{
			GetVehicleModelInfo(GetVehicleModel(vehicleid), VEHICLE_MODEL_INFO_SIZE, X, Y, Z);
			px = vx, py = vy;
			px += ((Y/2.0) * floatsin(-a,degrees));
			py += ((Y/2.0) * floatcos(-a,degrees));
			x = (px-vx)*floatcos(a, degrees)+(py-vy)*floatsin(a, degrees);
			y = -(px-vx)*floatsin(a, degrees)+(py-vy)*floatcos(a, degrees)-0.2;
			GetVehicleModelInfo(GetVehicleModel(vehicleid), VEHICLE_MODEL_INFO_WHEELSFRONT, X, Y, Z);
			z = (Z+0.5);
		}
		case VEH_PART_TRUNK://Behind
		{
			GetVehicleModelInfo(GetVehicleModel(vehicleid), VEHICLE_MODEL_INFO_SIZE, X, Y, Z);
			px = vx, py = vy;
			px += ((Y/2.0) * floatsin(-a+180.0,degrees));
			py += ((Y/2.0) * floatcos(-a+180.0,degrees));
			x = (px-vx)*floatcos(a, degrees)+(py-vy)*floatsin(a, degrees);
			y = -(px-vx)*floatsin(a, degrees)+(py-vy)*floatcos(a, degrees)+0.3;
			GetVehicleModelInfo(GetVehicleModel(vehicleid), VEHICLE_MODEL_INFO_WHEELSREAR, X, Y, Z);
			z = (Z+0.5);
		}
		case VEH_PART_PCAP:
		{
			GetVehicleModelInfo(GetVehicleModel(vehicleid), VEHICLE_MODEL_INFO_PETROLCAP, x, y, z);
			if(!GetVehiclePetrolCapSide(vehicleid)) y -= 2.0;
		}
	}
}

stock Float:GetVehiclePartAngle(vehicleid, part)
{
	new Float:a;
	GetVehicleZAngle(vehicleid, a);
	switch(part)
	{
		case VEH_PART_FTIRE,VEH_PART_HOOD: a -= 180.0;//Front Tire | Hood
		case VEH_PART_RFTIRE,VEH_PART_RRTIRE,VEH_PART_RMTIRE,VEH_PART_RFSEAT,VEH_PART_RRSEAT: a += 90.0;//Right Front/Mid/Rear Tires | Right Front/Rear Seats
		case VEH_PART_LFTIRE,VEH_PART_LRTIRE,VEH_PART_LMTIRE,VEH_PART_LFSEAT,VEH_PART_LRSEAT: a -= 90.0;//Left Front/Mid/Rear Tires | Left Front/Rear Seats
		case VEH_PART_PCAP:
		{
			new cap = GetVehiclePetrolCapSide(vehicleid);
			if (cap == 1) a += 90.0;
			if (cap == 2) a -= 90.0;
			if (cap == 4) a -= 180.0;
		}
	}
	return a;
}

stock SetPlayerNearVehiclePart(playerid, vehicleid, part, Float:offset = 0.5)
{
	new Float:pos[3],Float:a = GetVehiclePartAngle(vehicleid, part);
	GetPosNearVehiclePart(vehicleid, part, pos[0], pos[1], pos[2], offset);
	SetPlayerPos(playerid, pos[0], pos[1], pos[2]);
	SetPlayerFacingAngle(playerid, a);
	return 1;
}

stock IsPlayerNearVehiclePart(playerid, vehicleid, part, Float:radius = 0.5, Float:offset = 0.0)
{
	new Float:pos[3],model=GetVehicleModel(vehicleid);
	if(part == VEH_PART_PCAP)
	{
		if(!GetVehiclePetrolCapSide(vehicleid) || model == 557 || model == 486 || model == 592) radius += 1.5;
		else if(model == 471 || model == 571) radius += 0.5;
	}
	GetPosNearVehiclePart(vehicleid, part, pos[0], pos[1], pos[2], offset);
	if(IsPlayerInRangeOfPoint(playerid, radius, pos[0], pos[1], pos[2])) return 1;
	return 0;
}

stock GetVehiclePetrolCapSide(vehicleid)
{
	new model = GetVehicleModel(vehicleid);
	switch(model)
	{
		case 401,402,411,429,451,456,478,482,483,486,489,490,495,496,505,506,514,
		518,524,533,541,546,554,557,560..562,565,566,579,580,585,589,599,600,602,603: return 1;//Right
		case 400,403..405,408..410,413..416,418..423,426,427,431,433,434,436..440,
		442,443,445,448,455,458,459,461..463,467,468,470,471,475,477,479,480,485,491,492,494,
		498..500,502..504,507,508,515..517,521..523,525..529,534..536,540,542..544,547,549..552,
		555,558,559,568,571,573,574,578,581..583,586..588,596..598,601,605,609: return 2;//Left
		case 407,412,428,444,466,545,567,572,575,576,604: return 3;//Back
		case 424: return 4;//Front
	}
	return 0;//No Cap - Center
}

stock GetVehiclePartName(part)
{
	new partname[25];
	switch(part)
	{
		case VEH_PART_FTIRE: partname ="Front Tire";
		case VEH_PART_RTIRE: partname ="Rear Tire";
		case VEH_PART_RFTIRE: partname ="Right Front Tire";
		case VEH_PART_LFTIRE: partname ="Left Front Tire";
		case VEH_PART_RRTIRE: partname ="Right Rear Tire";
		case VEH_PART_LRTIRE: partname ="Left Rear Tire";
		case VEH_PART_RMTIRE: partname ="Right Mid Tire";
		case VEH_PART_LMTIRE: partname ="Left Mid Tire";
		case VEH_PART_RFSEAT: partname ="Right Front Seat";
		case VEH_PART_LFSEAT: partname ="Left Front Seat";
		case VEH_PART_RRSEAT: partname ="Right Rear Seat";
		case VEH_PART_LRSEAT: partname ="Left Rear Seat";
		case VEH_PART_HOOD: partname ="Hood";
		case VEH_PART_TRUNK: partname ="Trunk";
		case VEH_PART_PCAP: partname ="Petrol Cap";
	}
	return partname;
}

