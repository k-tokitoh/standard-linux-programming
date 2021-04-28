#!/bin/sh

. `dirname $0`/../common.sh

assert_equal "cat `dirname $0`/../index.sh" "`dirname $0`/../../commands/cat/bin/cat `dirname $0`/../index.sh"
