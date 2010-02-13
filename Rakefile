require 'rake'
require 'rake/clean'

NAME    = 'lulzKey'
RELEASE = '0.0.1'

CC      = 'llvm-g++'
CFLAGS  = "-Wall -Wextra -Wno-long-long -pedantic -fno-builtin -nostartfiles -nostdlib -nodefaultlibs -fno-stack-protector -fstrength-reduce -fomit-frame-pointer -finline-functions -fno-rtti -fno-exceptions -D___VERSION___='\"#{RELEASE}\"' -I./include -I./sources -I./lolibc/include"
LDFLAGS = '-T linker.ld -s -L./lolibc -static -llolibc'

CLEAN.include('sources/**/*.o', 'sources/**/*.ao')
CLOBBER.include(NAME)

SOURCES = {
    :ASM => FileList['sources/loader.S', 'sources/*/**/*.S'],
    :CPP => FileList['sources/**/*.cpp'],
}

CFLAGS << " -D_PANIC_#{ENV['PANIC'] || 'NAZI'}"

if not ARGV.include?('clean') and not ARGV.include?('clobber')
    case ENV['ARCH']
        when 'x86'
            CFLAGS << ' -D_ARCH_X86'
            ENV['32bit'] = 'true'
        else
            raise 'No arch was choosen.'
    end

    SOURCES[:ASM].exclude(/sources\/Processor\/(^#{ENV['ARCH']})\/.*\.cpp$/)
    SOURCES[:CPP].exclude(/sources\/Processor\/(^#{ENV['ARCH']})\/.*\.cpp$/)
end

if ENV['32bit']
    CFLAGS << ' -m32'
end

if ENV['OPTIMIZED'] != 'false'
    CFLAGS << ' -Os'
end

OBJECTS = FileList.new.include(SOURCES[:ASM].ext('ao')).include(SOURCES[:CPP].ext('o'))

task :default => [NAME]

rule '.o' => '.cpp' do |t|
    sh "#{CC} #{CFLAGS} -o #{t.name} -c #{t.source}"
end

rule '.ao' => '.S' do |t|
    sh "#{CC} #{CFLAGS} -o #{t.name} -c #{t.source}"
end

task :compile => OBJECTS

file NAME => :compile do
    sh "#{CC} #{CFLAGS} -o #{NAME} #{OBJECTS} #{LDFLAGS}"
end

task :help do
    puts %{\
Options:
    ARCH:   x86
}
end
