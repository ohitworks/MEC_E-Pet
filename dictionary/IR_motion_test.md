int irSensor = 7;//定义串口7  
bool irSensorOutput;//红外传感器输出信号数值  

void setup() {  
  // 初始化 串口通讯  
  Serial.begin(9600);  
  pinMode(irSensor, INPUT);     //连接人体红外感应模块的OUT引脚设置为输入模式  
  Serial.println("Hello world");//串口打印“Hello world”  
}  
    
  
void loop() {  
  irSensorOutput = digitalRead(irSensor);//读取并存储红外传感信号输出电平数值  
  if(irSensorOutput ==HIGH){  
    Serial.println("IR motion sensor output: High.");  
  }else{  
    Serial.println("IR motion sensor output: Low.");  
  }  
  delay(100);//间隔设置为1秒  
}  
  
