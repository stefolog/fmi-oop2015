# Script to put exercises in their
# respective folder.
require 'fileutils'

def create_dir(dir)
  Dir.mkdir(dir) unless File.exist?(dir)
end

def parse_dir_name(file)
  file.match('[e-x]{2}\d+').to_s
end

def move_file(file, dir)
  FileUtils.mv(file, "#{dir}/#{file}")
end

folder = Dir.pwd

files = Dir.entries(folder).select do |f|
  File.file?(f) && f.include?('ex')
end

if files.empty?
  puts 'No files to be moved.'
else
  files.each do |f|
    dir = parse_dir_name(f)
    puts "Creating directory for #{f}"
    create_dir(dir)
    puts 'Moving file.'
    move_file(f, dir)
  end

  puts 'All done.'
end
