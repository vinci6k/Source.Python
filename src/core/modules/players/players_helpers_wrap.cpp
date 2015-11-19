/**
* =============================================================================
* Source Python
* Copyright (C) 2012-2015 Source Python Development Team.  All rights reserved.
* =============================================================================
*
* This program is free software; you can redistribute it and/or modify it under
* the terms of the GNU General Public License, version 3.0, as published by the
* Free Software Foundation.
*
* This program is distributed in the hope that it will be useful, but WITHOUT
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
* FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
* details.
*
* You should have received a copy of the GNU General Public License along with
* this program.  If not, see <http://www.gnu.org/licenses/>.
*
* As a special exception, the Source Python Team gives you permission
* to link the code of this program (as well as its derivative works) to
* "Half-Life 2," the "Source Engine," and any Game MODs that run on software
* by the Valve Corporation.  You must obey the GNU General Public License in
* all respects for all other code used.  Additionally, the Source.Python
* Development Team grants this exception to all derivative works.
*/

//-----------------------------------------------------------------------------
// Includes.
//-----------------------------------------------------------------------------
#include "export_main.h"
#include "utilities/conversions.h"
#include "utilities/wrap_macros.h"
#include "modules/entities/entities_entity.h"

BOOST_PYTHON_OPAQUE_SPECIALIZED_TYPE_ID(CBaseEntity)


//-----------------------------------------------------------------------------
// Forward declarations.
//-----------------------------------------------------------------------------
void export_player_conversion_functions(scope);


//-----------------------------------------------------------------------------
// Declare the _players._helpers module.
//-----------------------------------------------------------------------------
DECLARE_SP_SUBMODULE(_players, _helpers)
{
	// Conversion functions...
	export_player_conversion_functions(_helpers);
}


//-----------------------------------------------------------------------------
// Exports conversion functions.
//-----------------------------------------------------------------------------
void export_player_conversion_functions(scope _helpers)
{
	// To Index conversions...
	EXPORT_CONVERSION_FUNCTION(unsigned int, Index, unsigned int, Userid, object(result));
	EXPORT_CONVERSION_FUNCTION(unsigned int, Index, IPlayerInfo *, PlayerInfo, object(result));

	// To Edict conversions...
	EXPORT_CONVERSION_FUNCTION(edict_t *, Edict, unsigned int, Userid, object(ptr(result)));
	EXPORT_CONVERSION_FUNCTION(edict_t *, Edict, IPlayerInfo *, PlayerInfo, object(ptr(result)));

	// To BaseHandle conversions...
	EXPORT_CONVERSION_FUNCTION(CBaseHandle, BaseHandle, unsigned int, Userid, object(result));
	EXPORT_CONVERSION_FUNCTION(CBaseHandle, BaseHandle, IPlayerInfo *, PlayerInfo, object(result));

	// To IntHandle conversions...
	EXPORT_CONVERSION_FUNCTION(unsigned int, IntHandle, unsigned int, Userid, object(result));
	EXPORT_CONVERSION_FUNCTION(unsigned int, IntHandle, IPlayerInfo *, PlayerInfo, object(result));

	// To Pointer conversions...
	EXPORT_CONVERSION_FUNCTION(CPointer, Pointer, unsigned int, Userid, object(result));
	EXPORT_CONVERSION_FUNCTION(CPointer, Pointer, IPlayerInfo *, PlayerInfo, object(result));

	// To UserID conversions...
	EXPORT_CONVERSION_FUNCTION(unsigned int, Userid, unsigned int, Index, object(result));
	EXPORT_CONVERSION_FUNCTION(unsigned int, Userid, edict_t *, Edict, object(result));
	EXPORT_CONVERSION_FUNCTION(unsigned int, Userid, CBaseHandle, BaseHandle, object(result));
	EXPORT_CONVERSION_FUNCTION(unsigned int, Userid, unsigned int, IntHandle, object(result));
	EXPORT_CONVERSION_FUNCTION(unsigned int, Userid, CPointer *, Pointer, object(result));
	EXPORT_CONVERSION_FUNCTION(unsigned int, Userid, IPlayerInfo *, PlayerInfo, object(result));
	EXPORT_CONVERSION_FUNCTION(unsigned int, Userid, CBaseEntity *, BaseEntity, object(result));
	
	// To PlayerInfo conversions...
	EXPORT_CONVERSION_FUNCTION(IPlayerInfo *, PlayerInfo, unsigned int, Index, object(ptr(result)));
	EXPORT_CONVERSION_FUNCTION(IPlayerInfo *, PlayerInfo, edict_t *, Edict, object(ptr(result)));
	EXPORT_CONVERSION_FUNCTION(IPlayerInfo *, PlayerInfo, CBaseHandle, BaseHandle, object(ptr(result)));
	EXPORT_CONVERSION_FUNCTION(IPlayerInfo *, PlayerInfo, unsigned int, IntHandle, object(ptr(result)));
	EXPORT_CONVERSION_FUNCTION(IPlayerInfo *, PlayerInfo, CPointer *, Pointer, object(ptr(result)));
	EXPORT_CONVERSION_FUNCTION(IPlayerInfo *, PlayerInfo, unsigned int, Userid, object(ptr(result)));
	EXPORT_CONVERSION_FUNCTION(IPlayerInfo *, PlayerInfo, CBaseEntity *, BaseEntity, object(ptr(result)));

	// To BaseEntity conversions...
	EXPORT_CONVERSION_FUNCTION(CBaseEntity *, BaseEntity, unsigned int, Userid, object(ptr((CBaseEntityWrapper*) result)));
	EXPORT_CONVERSION_FUNCTION(CBaseEntity *, BaseEntity, IPlayerInfo *, PlayerInfo, object(ptr((CBaseEntityWrapper*) result)));
}
