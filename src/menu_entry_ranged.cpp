/***************************************************************************
                          menu_entry_ranged.cpp  -  description
                             -------------------
    begin                : Jun 13 2007
    copyright            : (C) 2007 by Giuseppe D'Aqui'
    email                : kumber@tiscalinet.it
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License, Version 2,      *
 *   as published by the Free Software Foundation.                         *
 *                                                                         *
 ***************************************************************************/

#include "dephine.h"
#include "menu_entry_ranged.h"


void Menu_Entry_Ranged::set_current_value(Uint32 current_value)
{
	if((current_value>=m_range_begin)&&(current_value<=m_range_end))
	{
		m_current_value = current_value;
	}
	
}


	
const char* Menu_Entry_Ranged::get_string()
{
	static char result_buffer[512];
	char value_string[32];
	snprintf(value_string, sizeof(value_string), "%u", m_current_value);
	snprintf(result_buffer, sizeof(result_buffer), "%s%s", m_string.c_str(), value_string);
	return result_buffer;
}



	
void Menu_Entry_Ranged::set_string(const char* string)
{
	m_string = string;
}



	
void Menu_Entry_Ranged::action_left()
{
	if(m_current_value>m_range_begin) 
		m_current_value--;
}




void Menu_Entry_Ranged::action_right()
{
	if(m_current_value<m_range_end)
		 m_current_value++;
}
