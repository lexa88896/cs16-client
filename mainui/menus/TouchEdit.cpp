/*
Copyright (C) 1997-2001 Id Software, Inc.

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

*/

/*
 * This is empty menu that allows engine to draw touch editor
 */

#include "extdll.h"
#include "BaseMenu.h"
#include "Utils.h"
#include "keydefs.h"

class CMenuTouchEdit : public CMenuFramework
{
public:
	void Draw();
	const char *Key(int key, int down);
private:
	void _VidInit();
	int active;
};

static CMenuTouchEdit uiTouchEdit;


/*
=================
UI_TouchEdit_DrawFunc
=================
*/
void CMenuTouchEdit::Draw( void )
{
	if( !EngFuncs::GetCvarFloat("touch_in_menu") )
	{
		Hide();
		UI_TouchButtons_GetButtonList();
	}
}

/*
=================
UI_TouchEdit_KeyFunc
=================
*/
const char *CMenuTouchEdit::Key( int key, int down )
{
	if( down && key == K_ESCAPE )
	{
		EngFuncs::CvarSetString("touch_in_menu", "0");
		EngFuncs::ClientCmd(0, "touch_disableedit");
		Hide();
		return uiSoundOut;
	}
	return uiSoundNull;
}

/*
=================
UI_TouchEdit_Init
=================
*/
void CMenuTouchEdit::_VidInit()
{
	EngFuncs::CvarSetString("touch_in_menu", "1");
	EngFuncs::ClientCmd(0, "touch_enableedit");
}

/*
=================
UI_TouchEdit_Precache
=================
*/
void UI_TouchEdit_Precache( void )
{

}

/*
=================
UI_TouchEdit_Menu
=================
*/
void UI_TouchEdit_Menu( void )
{
	UI_TouchEdit_Precache();
	uiTouchEdit.Show();
}
