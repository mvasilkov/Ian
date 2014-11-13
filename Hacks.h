#pragma once

#include <memory>

/* make_unique() is missing from at least clang-600.0.54 */

template <typename Res> std::unique_ptr<Res> make_unique_noargs()
{
        return std::unique_ptr<Res>(new Res);
}

template <typename Res, typename... Args>
std::unique_ptr<Res> _make_unique(Args &&... args)
{
        return std::unique_ptr<Res>(new Res(std::forward<Args>(args)...));
}
