#!/bin/sh

assert_equal() {
    rm -rf tmp
    _red=0
    expected=$1; shift
    actual=$1; shift
    
    eval "$expected" >tmp.out.expected 2>tmp.err.expected
    eval "$actual" > tmp.out.actual 2> tmp.err.actual

    cmp tmp.out.actual tmp.out.expected >/dev/null 2>&1

    if [ "$?" != "0" ]
    then
        echo_red "stdout differ: \"$expected\" and \"$actual\""
        diff -u tmp.out.actual tmp.out.expected
        echo_red "----"
        _red=1
    fi

    cmp tmp.err.actual tmp.err.expected >/dev/null 2>&1

    if [ "$?" != "0" ]
    then
        echo_red "stdout differ: \"$expected\" and \"$actual\""
        diff -u tmp.err.actual tmp.err.exptected
        echo_red "----"
        _red=1
    fi

    if [ $_red = 0 ]
    then
        echo_green "."
    fi
}

echo_red() {
    echo -en "\e[31m"
    echo $1
}

echo_green() {
    echo -en "\e[32m"
    echo -n $1
}
