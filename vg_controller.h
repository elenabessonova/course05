#ifndef vg_controller_h
#define vg_controller_h

#include <vector>
#include "vg_types.h"
#include "vg_document.h"



class VG_controller
{
public:
    void process_commands();
    void run();
private:
    std::vector<VG_command> __command_queue;
    std::unique_ptr<VG_document> __document;
};

#endif /* vg_controller_h */
