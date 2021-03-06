## Configuration directives

### `weserv`

| syntax:      | <code>weserv on&#124;off</code> |
| :----------- | :------------------------------ |
| **default:** | `off`                           |
| **context:** | `http`, `server`, `location`    |

Enables or disables the Weserv module for NGINX requests.

### `weserv_mode`

| syntax:      | <code>weserv_mode proxy&#124;file</code> |
| :----------- | :--------------------------------------- |
| **default:** | `proxy`                                  |
| **context:** | `location`, `if in location`             |

Configure backend mode:
- `proxy` - process images from a remote server specified within the `?url=`
  query parameter.
- `file`  - process images from your local filesystem.

### `weserv_connect_timeout`

| syntax:      | `weserv_connect_timeout <timeout>` |
| :----------- | :--------------------------------- |
| **default:** | `5s`                               |
| **context:** | `http`, `server`, `location`       |

Defines a timeout for establishing a connection with a remote server.

### `weserv_send_timeout`

| syntax:      | `weserv_send_timeout <timeout>` |
| :----------- | :------------------------------ |
| **default:** | `5s`                            |
| **context:** | `http`, `server`, `location`    |

Sets a timeout for transmitting a request to a remote server. The timeout is
set only between two successive write operations, not for the transmission of
the whole request. If the remote server does not receive anything within this
time, the connection is closed.

### `weserv_read_timeout`

| syntax:      | `weserv_read_timeout <timeout>` |
| :----------- | :------------------------------ |
| **default:** | `15s`                           |
| **context:** | `http`, `server`, `location`    |

Defines a timeout for reading a response from a remote server. The timeout is
set only between two successive read operations, not for the transmission of
the whole response. If the remote server does not transmit anything within this
time, the connection is closed.

### `weserv_user_agent`

| syntax:      | `weserv_user_agent <user_agent>`                                        |
| :----------- | :---------------------------------------------------------------------- |
| **default:** | `Mozilla/5.0 (compatible; ImageFetcher/9.0; +http://images.weserv.nl/)` |
| **context:** | `http`, `server`, `location`, `if in location`                          |

Configures the User-Agent header that will be sent to a remote server.

### `weserv_max_size`

| syntax:      | `weserv_max_size <size>`                       |
| :----------- | :--------------------------------------------- |
| **default:** | `100m`                                         |
| **context:** | `http`, `server`, `location`, `if in location` |

Sets the maximum size of an image to be processed. Set to `0` to remove this
limit.

### `weserv_max_redirects`

| syntax:      | `weserv_max_redirects <redirects>`             |
| :----------- | :--------------------------------------------- |
| **default:** | `10`                                           |
| **context:** | `http`, `server`, `location`, `if in location` |

Sets the maximum number of redirection-followings allowed.

### `weserv_max_pages`

| syntax:      | `weserv_max_pages <pages>`                     |
| :----------- | :--------------------------------------------- |
| **default:** | `256`                                          |
| **context:** | `http`, `server`, `location`, `if in location` |

Sets the maximum number of pages to extract for multi-page input (GIF, TIFF,
PDF, WebP). Set to `0` to remove this limit.

### `weserv_limit_input_pixels`

| syntax:      | `weserv_limit_input_pixels <pixels>`           |
| :----------- | :--------------------------------------------- |
| **default:** | `71000000`                                     |
| **context:** | `http`, `server`, `location`, `if in location` |

Sets the maximum number of pixels (width x height) of an input image to be
processed. Assumes image dimensions contained in the input metadata can be
trusted. Set to `0` to remove this limit.

### `weserv_limit_output_pixels`

| syntax:      | `weserv_limit_output_pixels <pixels>`          |
| :----------- | :--------------------------------------------- |
| **default:** | `71000000`                                     |
| **context:** | `http`, `server`, `location`, `if in location` |

Sets the maximum number of pixels (width x height) of an output image, after
any upscaling. Set to `0` to remove this limit.

### `weserv_default_quality`

| syntax:      | `weserv_default_quality <quality>`             |
| :----------- | :--------------------------------------------- |
| **default:** | `85`                                           |
| **context:** | `http`, `server`, `location`, `if in location` |

Sets the default quality (1-100) to use for JPEG, WebP and TIFF images when
`&q=` is not specified.

### `weserv_default_level`

| syntax:      | `weserv_default_level <level>`                 |
| :----------- | :--------------------------------------------- |
| **default:** | `6`                                            |
| **context:** | `http`, `server`, `location`, `if in location` |

Sets the default zlib compression (0-9) to use for PNG images when `&l=` is
not specified.

### `weserv_fail_on_error`

| syntax:      | <code>weserv_fail_on_error on&#124;off</code>  |
| :----------- | :--------------------------------------------- |
| **default:** | `off`                                          |
| **context:** | `http`, `server`, `location`, `if in location` |

Sets the processing behavior when loading invalid images. By default, the Weserv
module does a "best effort" to decode images, even if the data is corrupt or
invalid. Set  this flag to `on` if you would rather to halt processing and raise
an error when loading invalid images.
