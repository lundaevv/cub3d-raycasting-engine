#include "../../includes/main.h"

static const char *msg_for_err(t_err err)
{
    static const char *msgs[] = {
        NULL,
        ERRMSG_ARGS,
        ERRMSG_EXT,
        ERRMSG_OPEN,
        ERRMSG_READ,
        ERRMSG_MEM,
        ERRMSG_CONF_DUP,
        ERRMSG_CONF_MISS,
        ERRMSG_CONF_PATH,
        ERRMSG_CONF_COLOR,
        ERRMSG_MAP_EMPTY,
        ERRMSG_MAP_CHAR,
        ERRMSG_MAP_PLAYER,
        ERRMSG_MAP_OPEN,
        ERRMSG_PARSE
    };
    if (err <= 0 || err >= (t_err)(sizeof(msgs) / sizeof(msgs[0])))
        return ("unknown error");
    return (msgs[err]);
}

int print_errno(t_err err)
{
    if (err == ERR_OK)
        return (0);
    return (print_msg(ERR_FMT, msg_for_err(err), 1));
}
