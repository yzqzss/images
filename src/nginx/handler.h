#pragma once

extern "C" {
#include <ngx_http.h>
}

#include <memory>
#include <string>
#include <utility>

namespace weserv {
namespace nginx {

/**
 * The request handler for locations configured with weserv.
 */
ngx_int_t ngx_weserv_request_handler(ngx_http_request_t *r);

}  // namespace nginx
}  // namespace weserv
