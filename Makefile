SOURCE_DIR=src
BUILD_DIR=build
include $(N64_INST)/include/n64.mk

PROJECT_NAME = myproject

all: $(PROJECT_NAME).z64
.PHONY: all

ASSETS_DIR = assets
FILESYSTEM_DIR = filesystem

assets = $(wildcard $(ASSETS_DIR)/*.png)
assets_conv = $(patsubst $(ASSETS_DIR)/%.png, $(FILESYSTEM_DIR)/%.sprite, $(assets))

assets_wav = $(wildcard $(ASSETS_DIR)/*.wav) $(wildcard $(ASSETS_DIR)/*.WAV)
assets_mp3 = $(wildcard $(ASSETS_DIR)/*.mp3) $(wildcard $(ASSETS_DIR)/*.MP3)
assets_xm = $(wildcard $(ASSETS_DIR)/*.xm) $(wildcard $(ASSETS_DIR)/*.XM)
assets_ym = $(wildcard $(ASSETS_DIR)/*.ym) $(wildcard $(ASSETS_DIR)/*.YM)
assets_audio_conv = $(patsubst $(ASSETS_DIR)/%.wav, $(FILESYSTEM_DIR)/%.wav64, $(assets_wav)) \
                    $(patsubst $(ASSETS_DIR)/%.WAV, $(FILESYSTEM_DIR)/%.wav64, $(assets_wav)) \
					$(patsubst $(ASSETS_DIR)/%.mp3, $(FILESYSTEM_DIR)/%.wav64, $(assets_mp3)) \
                    $(patsubst $(ASSETS_DIR)/%.MP3, $(FILESYSTEM_DIR)/%.wav64, $(assets_mp3))
					$(patsubst $(ASSETS_DIR)/%.xm, $(FILESYSTEM_DIR)/%.xm64, $(assets_xm)) \
                    $(patsubst $(ASSETS_DIR)/%.XM, $(FILESYSTEM_DIR)/%.xm64, $(assets_xm)) \
                    $(patsubst $(ASSETS_DIR)/%.ym, $(FILESYSTEM_DIR)/%.ym64, $(assets_ym)) \
                    $(patsubst $(ASSETS_DIR)/%.YM, $(FILESYSTEM_DIR)/%.ym64, $(assets_ym))

all_assets_conv = $(assets_conv) $(assets_audio_conv)

WAV64_AUDIOCONV_FLAGS ?=
XM_AUDIOCONV_FLAGS ?=
YM_AUDIOCONV_FLAGS ?=
MKSPRITE_FLAGS ?=

CFLAGS += -Iinclude
CXXFLAGS = $(CFLAGS)

SRCS_C = $(wildcard $(SOURCE_DIR)/**/*.c)
SRCS_CPP = $(wildcard $(SOURCE_DIR)/**/*.cpp) $(wildcard $(SOURCE_DIR)/**/*.cc)
OBJS = $(patsubst $(SOURCE_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRCS_C)) $(patsubst $(SOURCE_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRCS_CPP)) $(patsubst $(SOURCE_DIR)/%.cc, $(BUILD_DIR)/%.o, $(SRCS_CPP))

$(FILESYSTEM_DIR)/%.sprite: $(ASSETS_DIR)/%.png
	@mkdir -p $(dir $@)
	@echo "    [SPRITE] $@"
	@$(N64_MKSPRITE) $(MKSPRITE_FLAGS) -o $(FILESYSTEM_DIR) "$<"

$(FILESYSTEM_DIR)/%.wav64: $(ASSETS_DIR)/%.wav
	@mkdir -p $(dir $@)
	@echo "    [AUDIOCONV] $@"
	@$(N64_AUDIOCONV) $(WAV64_AUDIOCONV_FLAGS) -o $(FILESYSTEM_DIR) "$<"

$(FILESYSTEM_DIR)/%.wav64: $(ASSETS_DIR)/%.mp3
	@mkdir -p $(dir $@)
	@echo "    [AUDIOCONV] $@"
	@$(N64_AUDIOCONV) $(WAV64_AUDIOCONV_FLAGS) -o $(FILESYSTEM_DIR) "$<"

$(FILESYSTEM_DIR)/%.wav64: $(ASSETS_DIR)/%.MP3
@mkdir -p $(dir $@)
@echo "    [AUDIOCONV] $@"
@$(N64_AUDIOCONV) $(WAV64_AUDIOCONV_FLAGS) -o $(FILESYSTEM_DIR) "$<"

$(FILESYSTEM_DIR)/%.wav64: $(ASSETS_DIR)/%.wav
	@mkdir -p $(dir $@)
	@echo "    [AUDIOCONV] $@"
	@$(N64_AUDIOCONV) $(WAV64_AUDIOCONV_FLAGS) -o $(FILESYSTEM_DIR) "$<"

$(FILESYSTEM_DIR)/%.xm64: $(ASSETS_DIR)/%.xm
	@mkdir -p $(dir $@)
	@echo "    [AUDIOCONV] $@"
	@$(N64_AUDIOCONV) $(XM_AUDIOCONV_FLAGS) -o $(FILESYSTEM_DIR) "$<"

$(FILESYSTEM_DIR)/%.xm64: $(ASSETS_DIR)/%.XM
	@mkdir -p $(dir $@)
	@echo "    [AUDIOCONV] $@"
	@$(N64_AUDIOCONV) $(XM_AUDIOCONV_FLAGS) -o $(FILESYSTEM_DIR) "$<"

$(FILESYSTEM_DIR)/%.ym64: $(ASSETS_DIR)/%.ym
	@mkdir -p $(dir $@)
	@echo "    [AUDIOCONV] $@"
	@$(N64_AUDIOCONV) $(YM_AUDIOCONV_FLAGS) -o $(FILESYSTEM_DIR) "$<"

$(FILESYSTEM_DIR)/%.ym64: $(ASSETS_DIR)/%.YM
	@mkdir -p $(dir $@)
	@echo "    [AUDIOCONV] $@"
	@$(N64_AUDIOCONV) $(YM_AUDIOCONV_FLAGS) -o $(FILESYSTEM_DIR) "$<"

$(BUILD_DIR)/%.o: $(SOURCE_DIR)/%.c
	@mkdir -p $(dir $@)
	@echo "    [CC] $<"
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: $(SOURCE_DIR)/%.cc
	@mkdir -p $(dir $@)
	@echo "    [CXX] $<"
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: $(SOURCE_DIR)/%.cpp
	@mkdir -p $(dir $@)
	@echo "    [CXX] $<"
	$(CXX) $(CXXFLAGS) -c $< -o $@
	

$(PROJECT_NAME).z64: N64_ROM_TITLE="$(PROJECT_NAME)"
$(PROJECT_NAME).z64: $(BUILD_DIR)/$(PROJECT_NAME).dfs

$(BUILD_DIR)/$(PROJECT_NAME).elf: $(OBJS)
$(BUILD_DIR)/$(PROJECT_NAME).dfs: $(all_assets_conv)
	@echo "	[DFS] $@"
	@if [ ! -s "$<"]; then rm -f "$<"; fi
	$(N64_MKDFS) "$@" $(FILESYSTEM_DIR) >/dev/null

clean:
	rm -f $(BUILD_DIR)/* *.z64
.PHONY: clean

-include $(wildcard $(BUILD_DIR)/*.d)