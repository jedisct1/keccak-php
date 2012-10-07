--TEST--
Test function keccak_hash() by calling it with expected arguments
--CREDITS--
Bryan C. Geraghty <bryan@ravensight.org>
--SKIPIF--
<?php if (!extension_loaded("keccak")) print "skip"; ?>
--FILE--
<?php

var_dump(keccak_hash(0) === keccak_hash(0));
var_dump(keccak_hash(0) !== keccak_hash(1));
var_dump(keccak_hash(0) !== keccak_hash(3));
var_dump(keccak_hash(0) !== keccak_hash(9));
var_dump(keccak_hash(0) !== keccak_hash(10));

$data = "\xde\xad\xbe\xef";

var_dump(bin2hex(keccak_hash($data)));
var_dump(base64_encode(keccak_hash($data)));

// string(88) "Jkpv6J5fTCUsOoeF25cTwNi+8GzkElvIjJYnG46aX3RTEZscoUyeDuTlN5tg1VjABOYR2ORkdDmNHp2etlgo2Q=="
// string(88) "Jkpv6J5fTCUsOoeF25cTwNi+8GzkElvIjJYnG46aX3RTEZscoUyeDuTlN5tg1VjABOYR2ORkdDmNHp2etlgo2Q=="

?>
--EXPECT--
bool(true)
bool(true)
bool(true)
bool(true)
bool(true)
string(128) "2ba2bcffbaae660ab5f0202123f431009df88262a269e3be6877c814b06c986a5f7d7a8d7494ce15bd32cfb0764dfbe4a747a65f33e37e50dbb5de78475811fd"
string(88) "K6K8/7quZgq18CAhI/QxAJ34gmKiaeO+aHfIFLBsmGpffXqNdJTOFb0yz7B2Tfvkp0emXzPjflDbtd54R1gR/Q=="
