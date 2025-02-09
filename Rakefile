# 项目构建任务

require 'rake'
require 'rake/clean'

SOURCES_DIR = 'src'
TARGET_DIR = 'out'

SOURCES_LIST = FileList.new(
  "#{SOURCES_DIR}/**/*.h",
  "#{SOURCES_DIR}/**/*.c"
)

# 编译器标志
CFLAGS = "-I#{SOURCES_DIR} -Wall -Wextra -pedantic"

MAIN = "#{SOURCES_DIR}/main.c"
ADDITIONAL = FileList.new("#{SOURCES_DIR}/**/*.c").exclude(MAIN)

EXECUTABLE = "#{TARGET_DIR}/game.exe"

# 外部库依赖
INCLUDE_LIBRARIES = %w[SDL3 SDL3-image SDL3-ttf].freeze
INCLUDE_LIBRARIES_LIST = INCLUDE_LIBRARIES.join(' ')
INCLUDE_CFLAGS = `pkg-config --cflags #{INCLUDE_LIBRARIES_LIST}`.chomp
INCLUDE_LDFLAGS = `pkg-config --libs #{INCLUDE_LIBRARIES_LIST}`.chomp

# 清理规则
CLEAN.include("#{TARGET_DIR}/*")

# 可执行文件生成规则
file EXECUTABLE => SOURCES_LIST do
  mkdir_p TARGET_DIR
  sh "gcc -g #{CFLAGS} #{INCLUDE_CFLAGS} #{MAIN} #{ADDITIONAL} -o #{EXECUTABLE} #{INCLUDE_LDFLAGS}"
end

desc "生成可执行文件 #{EXECUTABLE}"
task build: EXECUTABLE

desc '运行项目'
task run: :build do
  exec EXECUTABLE
end

# 默认任务为运行项目
task default: :run
