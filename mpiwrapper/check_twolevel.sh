#!/bin/sh

set -euo pipefail

plugin=$1

if test ! -f "$plugin"; then
    echo "*** ERROR: plugin $plugin does not exist"
    exit 1
fi

if ! otool -hV "$plugin" | grep -q ' TWOLEVEL\( \|$\)'; then
    echo "*** ERROR: plugin $plugin does not use a two-level namespace"
    echo otool -hV "$plugin"
    otool -hV "$plugin"
    exit 1
fi
