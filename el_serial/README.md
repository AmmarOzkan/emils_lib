## el_serial Alt kütüphanesi
### USBSERIAL sınıfı
Bu sınıf USB seri bağlamada yazmayı ve okumayı sağlar(okuma eklenecek)
#### USBSERIAL::USBSERIAL(std::string portname) oluşturucu
Bu oluşturucu usb port ismini alarak portu üzerinde çalışmaya hazır hale getirir.
#### USBSERIAL::PortClose()
Portu kapatır.
#### USBSERIAL::WriteToPort(const void* bytes, int num)
Yazılacak veri sayısını ve verileri alarak usb porta yazar.
