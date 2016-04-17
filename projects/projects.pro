CONFIG += ordered

TEMPLATE = subdirs
SUBDIRS = lib gui

gui.depends = lib
