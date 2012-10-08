/*
  +----------------------------------------------------------------------+
  | PHP Version 5                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2012 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author:                                                              |
  +----------------------------------------------------------------------+
*/

/* $Id$ */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_keccak.h"
#include "keccak-impl.h"

#ifndef WORDS_BIGENDIAN
# include <arpa/inet.h>
#endif

const zend_function_entry keccak_functions[] = {
    PHP_FE(keccak_hash, NULL)
#ifdef PHP_FE_END
    PHP_FE_END
#else
    { NULL, NULL, NULL }
#endif
};

/* {{{ keccak_module_entry
 */
zend_module_entry keccak_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
    STANDARD_MODULE_HEADER,
#endif
    "keccak",
    keccak_functions,
    PHP_MINIT(keccak),
    PHP_MSHUTDOWN(keccak),
    NULL,
    NULL,
    PHP_MINFO(keccak),
#if ZEND_MODULE_API_NO >= 20010901
    "1.0",
#endif
    STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_KECCAK
ZEND_GET_MODULE(keccak)
#endif

/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(keccak)
{
    return SUCCESS;
}
/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION
 */
PHP_MSHUTDOWN_FUNCTION(keccak)
{
    return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(keccak)
{
    php_info_print_table_start();
    php_info_print_table_header(2, "keccak support", "enabled");
    php_info_print_table_end();
}
/* }}} */

PHP_FUNCTION(keccak_hash)
{
    unsigned char  hash[64U];
    char          *key = NULL;
    char          *message = NULL;
    int            message_size;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s",
                              &message, &message_size) == FAILURE) {
        return;
    }
    if (message_size < 0) {
        php_error_docref(NULL TSRMLS_CC, E_WARNING, "Empty message");
        RETURN_FALSE;
    }
    keccak(hash, (const unsigned char *) message, (size_t) message_size);

    RETURN_STRINGL((void *) &hash, sizeof hash, 1);
}

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
