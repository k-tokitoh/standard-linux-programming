test() {
    files=`find $(dirname $0)/commands -name *.sh`
    
    for file in $files; do
        eval $file
    done
    echo ""
}

test
