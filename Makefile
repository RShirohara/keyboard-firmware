.PHONY: git-submodule qmk-clean qmk-init qmk-compile qmk-flash

KB := ${kb}
KR := ${kr}
KM := ${km}

git-submodule:
	git submodule update --remote
	git submodule update --init --recursive

qmk-clean:
	rm -rf $(shell pwd)/build/qmk/qmk_firmware/keyboards/${KB}
	rm -rf $(shell pwd)/src/${KB}/qmk/qmk_firmware/dist
	qmk clean
	cd $(shell pwd)/build/qmk/qmk_firmware; git reset --hard

qmk-init: qmk-clean
	cp -RT $(shell pwd)/src/${KB}/qmk/qmk_firmware $(shell pwd)/build/qmk/qmk_firmware/keyboards/${KB}
	mkdir -p $(shell pwd)/src/${KB}/qmk/qmk_firmware/dist

qmk-compile: qmk-init
	$(eval FILE := $(shell echo "${kb}_${kr}_${km}" | sed 's/\//_/'))
	cd $(shell pwd)/build/qmk/qmk_firmware; qmk compile -kb ${KB}/${KR} -km ${KM}
	cp $(shell pwd)/build/qmk/qmk_firmware/.build/${FILE}.elf $(shell pwd)/src/${KB}/qmk/qmk_firmware/dist/${FILE}.elf | true
	cp $(shell pwd)/build/qmk/qmk_firmware/.build/${FILE}.hex $(shell pwd)/src/${KB}/qmk/qmk_firmware/dist/${FILE}.hex | true

qmk-flash: qmk-init
	cd $(shell pwd)/build/qmk/qmk_firmware; qmk flash -kb ${KB}/${KR} -km ${KM}

