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

#ifndef PHP_KECCAK_H
#define PHP_KECCAK_H

extern zend_module_entry keccak_module_entry;
#define phpext_keccak_ptr &keccak_module_entry

#ifdef PHP_WIN32
#	define PHP_KECCAK_API __declspec(dllexport)
#elif defined(__GNUC__) && __GNUC__ >= 4
#	define PHP_KECCAK_API __attribute__ ((visibility("default")))
#else
#	define PHP_KECCAK_API
#endif

#ifdef ZTS
#include "TSRM.h"
#endif

PHP_MINIT_FUNCTION(keccak);
PHP_MSHUTDOWN_FUNCTION(keccak);
PHP_RINIT_FUNCTION(keccak);
PHP_RSHUTDOWN_FUNCTION(keccak);
PHP_MINFO_FUNCTION(keccak);

#ifdef ZTS
#define KECCAK_G(v) TSRMG(keccak_globals_id, zend_keccak_globals *, v)
#else
#define KECCAK_G(v) (keccak_globals.v)
#endif

PHP_FUNCTION(keccak_hash);

#endif	/* PHP_KECCAK_H */

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
