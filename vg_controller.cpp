
#include <stdio.h>
#include <unistd.h>
#include "vg_controller.h"


void VG_controller::process_commands()
{
    for (auto & cmd : __command_queue)
    {
        switch(cmd.number)
        {
            case VG_CMD::NEW_DOC :
            {
                __document->make_new_doc(cmd.payload);
                break;
            }
            case VG_CMD::EXPORT_DOC :
            {
                __document->export_doc(cmd.payload);
                break;
            }
            case VG_CMD::IMPORT_DOC :
            {
                __document->import_doc(cmd.payload);
                break;
            }
            case VG_CMD::DRAW_LINE :
            {
                __document->add_vg_element(std::make_shared<VG_element>(cmd.payload));
                break;
            }
            case VG_CMD::REMOVE_LINE :
            {
                __document->remove_vg_element(std::make_shared<VG_element>(cmd.payload));
                break;
            }
            
            default:
                break;
        }
            
    }
    __command_queue.clear();
}


void VG_controller::run()
{
    while(true)
    {
        process_commands();
        sleep(1);
    }
}
