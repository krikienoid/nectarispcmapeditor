TEMPLATE = subdirs

SUBDIRS = \
    src/raw \
    src/nec \
    src/app \
    src/test

app.depends = src/raw
app.depends = src/nec
test.depends = src/raw
test.depends = src/nec
src/nec.depends = src/raw

OTHER_FILES += \
    defaults.pri \
    deployment.pri
