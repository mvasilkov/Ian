#pragma once

#include <memory>

template <typename Res> std::unique_ptr<Res> make_unique_noargs()
{
        return std::unique_ptr<Res>(new Res);
}
