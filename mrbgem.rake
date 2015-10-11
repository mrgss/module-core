MRuby::Gem::Specification.new('mrgss_core') do |spec|
  spec.license = 'MIT'
  spec.authors = 'mrgss developers'
  
  spec.mruby.cc.defines << "GLEW_STATIC"
	if ENV['OS'] == 'Windows_NT'
	  spec.mruby.linker.library_paths.push("#{File.dirname(__FILE__)}/lib/win")
	  spec.linker.libraries << 'glew32'
	  spec.linker.libraries << 'Ws2_32'
	  spec.linker.libraries << 'pthread'
	  spec.linker.libraries << 'SDL2'
	  spec.linker.libraries << 'SDL2main'
	  spec.linker.libraries << 'SDL2_image'
	  spec.linker.libraries << 'SDL2_ttf'
	  spec.linker.libraries << 'opengl32'
	  spec.linker.libraries << 'kazmath'
	  spec.linker.libraries << 'freetype'
	  spec.linker.libraries << 'jpeg'
	  spec.linker.libraries << 'png'
	  spec.linker.libraries << 'png16'
	  spec.linker.libraries << 'turbojpeg'
	  spec.linker.libraries << 'dinput8'
	  spec.linker.libraries << 'iconv'
	  spec.linker.libraries << 'dxguid'
	  spec.linker.libraries << 'dxerr8'
	  spec.linker.libraries << 'user32'
	  spec.linker.libraries << 'gdi32'
	  spec.linker.libraries << 'winmm'
	  spec.linker.libraries << 'imm32'
	  spec.linker.libraries << 'ole32'
	  spec.linker.libraries << 'oleaut32'
	  spec.linker.libraries << 'shell32'
	  spec.linker.libraries << 'version'
	  spec.linker.libraries << 'uuid'
	  spec.linker.libraries << 'z'
	else
	  spec.mruby.linker.library_paths.push("#{File.dirname(__FILE__)}/lib/lin")
	  spec.mruby.linker.libraries << 'GLEW'
	  spec.mruby.linker.libraries << 'GL'
	  spec.mruby.linker.libraries << 'kazmath'
	  spec.mruby.linker.libraries << 'pthread'
	  spec.mruby.linker.libraries << 'jpeg'
	  spec.mruby.linker.libraries << 'png'
	  spec.mruby.linker.libraries << 'png12'
	  spec.mruby.linker.libraries << 'turbojpeg'
	  spec.mruby.linker.libraries << 'SDL2'
	  spec.mruby.linker.libraries << 'SDL2main'
	  spec.mruby.linker.libraries << 'SDL2_image'
	  spec.mruby.linker.libraries << 'z'
	  spec.mruby.linker.libraries << 'dl'
	  spec.mruby.linker.libraries << 'pthread'
  end
end
