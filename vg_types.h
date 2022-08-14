#ifndef vg_types_h
#define vg_types_h

#include <string>


enum class VG_CMD
{
    NEW_DOC,
    EXPORT_DOC,
    IMPORT_DOC,
    DRAW_LINE,
    REMOVE_LINE,
    
    UNKNOWN
};



struct VG_command
{
    VG_CMD number;
    std::string payload;
};

#endif /* vg_types_h */
