#ifndef _SLIST_EXCEPTIONS_HPP_
#define _SLIST_EXCEPTIONS_HPP_

#include <stdexcept>
#include <string>

namespace Data{
    class NodeNotFoundException : public std::runtime_error {
    public:
        explicit NodeNotFoundException(const std::string& msg = "Node qui n'existe pas")
            : std::runtime_error(msg) {}
    };
}


#endif // _SLIST_EXCEPTIONS_HPP_