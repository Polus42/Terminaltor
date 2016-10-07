#include "SubMenuCommand.h"

SubMenuCommand::SubMenuCommand( Menu* menu, int index ) :
m( menu ),
m_index( index )
{
}

SubMenuCommand::~SubMenuCommand()
{
}

void SubMenuCommand::execute()
{
	m->LoadChild( m_index );
}