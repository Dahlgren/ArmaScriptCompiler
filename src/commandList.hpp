#pragma once

namespace sqf::runtime
{
    class runtime;
}

class CommandList {
public:
    static void init(sqf::runtime::runtime& runtime);
};