// Copyright (c) 2017-2018 The Merit Foundation developers
#include "safemode.h"

#include "rpc/protocol.h"
#include "util.h"
#include "warnings.h"

void ObserveSafeMode()
{
    std::string warning = GetWarnings("rpc");
    if (warning != "" && !gArgs.GetBoolArg("-disablesafemode", DEFAULT_DISABLE_SAFEMODE)) {
        throw JSONRPCError(RPC_FORBIDDEN_BY_SAFE_MODE, std::string("Safe mode: ") + warning);
    }
}

