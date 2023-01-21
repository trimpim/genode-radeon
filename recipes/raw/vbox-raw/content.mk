RAW_IMAGES := disk1.vmdk disk2.vmdk

content: init.config machine.vbox6 $(RAW_IMAGES)

init.config:
	cp $(REP_DIR)/recipes/raw/vbox-raw/$@ $@

machine.vbox6:
	cp $(REP_DIR)/recipes/raw/vbox-raw/$@ $@

$(RAW_IMAGES):
	cp $(REP_DIR)/recipes/raw/vbox-raw/$@ $@
