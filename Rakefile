require 'rake'
require 'rake/clean'

NAME    = 'lulzKey'
RELEASE = '0.0.1'

CC      = 'llvm-g++'
CFLAGS  = "-m32 -Wall -Wextra -Wno-long-long -pedantic -fno-builtin -nostartfiles -nostdlib -nodefaultlibs -fno-stack-protector -fstrength-reduce -fomit-frame-pointer -finline-functions -fno-rtti -fno-exceptions -D___VERSION___='\"#{RELEASE}\"' -I./include -I./sources -I./lolibc/include"
LDFLAGS = '-T linker.ld -s -L./lolibc -static -llolibc'

CLEAN.include('sources/**/*.o', 'sources/**.ao')
CLOBBER.include(NAME)

SOURCES = {
    :C   => FileList['sources/**/*.cpp'].exclude('sources/Processor/**'),
    :ASM => FileList['sources/**/*.S'].exclude('sources/Processor/**')
}

OBJECTS = FileList[].include(SOURCES[:C].ext('o')).include(SOURCES[:ASM].ext('ao'))

task :default => [NAME]

rule '.o' => '.cpp' do |t|
    sh "#{CC} #{CFLAGS} -o #{t.name} -c #{t.source}"
end

rule '.ao' => '.S' do |t|
    sh "#{CC} #{CFLAGS} -o #{t.name} -c #{t.source}"
end

task :arch do
    case ENV['ARCH']
        when 'x86'
            C_SOURCES.include('sources/Processor/x86/**.cpp')
            ASM_SOURCES.include('sources/Processor/x86/**.S')
            CFLAGS << ' -D_LKEY_X86'
        else
            raise 'No arch was choosen.'
    end
end

task :compile => [:arch].concat(OBJECTS)

file NAME => :compile do
    sh "#{CC} #{CFLAGS} -o #{NAME} #{OBJECTS} #{LDFLAGS}"
end

task :help do
    puts %{\
Options:
    ARCH:   x86
}
end
