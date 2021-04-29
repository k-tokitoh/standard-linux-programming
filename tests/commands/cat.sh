#!/bin/sh

. `dirname $0`/../common.sh

assert_equal \
    "cat `dirname $0`/../index.sh" \
    "`dirname $0`/../../commands/cat/cat `dirname $0`/../index.sh"

assert_equal \
    "cat `dirname $0`/../index.sh `dirname $0`/../common.sh" \
    "`dirname $0`/../../commands/cat/cat `dirname $0`/../index.sh `dirname $0`/../common.sh"

assert_equal \
    "cat < `dirname $0`/../index.sh" \
    "`dirname $0`/../../commands/cat/cat < `dirname $0`/../index.sh"

assert_equal \
    "cat < `dirname $0`/../index.sh < `dirname $0`/../common.sh" \
    "`dirname $0`/../../commands/cat/cat < `dirname $0`/../index.sh < `dirname $0`/../common.sh"
