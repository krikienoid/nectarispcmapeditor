TEMPLATE = subdirs

SUBDIRS = \
    src \
    src/bytes \
    src/nec \
    app \
    test

app.depends = src
test.depends = src
src/nec.depends = src/bytes

OTHER_FILES += \
    defaults.pri \
    deployment.pri
