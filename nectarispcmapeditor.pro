TEMPLATE = subdirs

SUBDIRS = \
    src/bytes \
    src/nec \
    app \
    test

app.depends = src/bytes
app.depends = src/nec
test.depends = src/bytes
test.depends = src/nec
src/nec.depends = src/bytes

OTHER_FILES += \
    defaults.pri \
    deployment.pri
