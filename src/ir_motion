int irSensor = 7;     // define IR sensor serial port (7) 定义串口7
bool irSensorOutput;  // Output signal value of the infrared sensor 红外传感器输出信号数值
int ir=0;
void setup() {
    // Initializing serial port communication
    // 初始化 串口通讯
    Serial.begin(9600);
    // The OUT pin connected to the human infrared induction module is set to the input mode
    // 连接人体红外感应模块的OUT引脚设置为输入模式
    pinMode(irSensor, INPUT);
  Serial.println("Hello world");  // serial print test 串口打印“Hello world”
}

void loop() {
    // Read and store infrared sensing signal output level values.
    // 读取并存储红外传感信号输出电平数值
  irSensorOutput = digitalRead(irSensor);
  if(irSensorOutput ==HIGH){
    Serial.println("IR motion sensor output: High.");
    ir=1;
  }else{
    Serial.println("IR motion sensor output: Low.");
    ir=2;
  }
  delay(100);  // The cycle interval is set to 0.1s 间隔设置为0.1秒
}
