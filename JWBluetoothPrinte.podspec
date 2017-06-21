
Pod::Spec.new do |s|

  s.name         = "JWBluetoothPrinte"
  s.version      = "1.0.0"
  s.summary      = "蓝牙连接打印机进行小票打印"
  s.description  = <<-DESC
                   "蓝牙连接打印机进行小票打印"
                   DESC

  s.homepage     = "https://github.com/kafeidou1991/JWBluetoothPrinte"
  s.license      = "MIT"
  s.author             = { "张竟巍" => "38251725@qq.com" }
  s.platform     = :ios, "7.0"
  s.source       = { :git => "https://github.com/kafeidou1991/JWBluetoothPrinte.git", :tag => s.version}
  s.source_files  = "JWBluetoothPrinte/**/*.{h,m}"
  s.requires_arc = true

end
