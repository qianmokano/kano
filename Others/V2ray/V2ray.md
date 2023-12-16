
第一次安装v2rayA后，发现无法访问 UI 界面，原来安装完毕后 v2rayA 默认不会设置开机自动启动，需要手动启动相关服务，执行命令：

 systemctl enable --now v2raya.service

升级安装也不会自动重启正在运行的 v2rayA ，需要重启已经运行的 v2rayA，执行命令：

systemctl restart v2raya.service

执行以上命令后，现在可以进入v2rayA登陆UI界面了。在第一次进入页面时，你需要创建一个管理员账号，请妥善保管你的用户名密码，如果遗忘，使用sudo v2raya --reset-password命令重置。

然后继续使用v2rayA时，又弹出提示：

检测到 geosite.dat, geoip.dat 文件或 v2ray-core 可能未正确安装，请检查

解决思路为下载安装v2ray/xray core。

v2ray core: https://github.com/v2fly/v2ray-core

xray core: https://github.com/XTLS/Xray-core

可以在上面任何一个网趾下载安装文件，下载的时候需要注意你的 CPU 架构，下载好之后解开压缩包，然后把可执行文件复制到 /usr/local/bin/ 或 /usr/bin/（推荐前者），把几个 dat 格式的文件复制到 /usr/local/share/v2ray/ 或者 /usr/share/v2ray/（推荐前者，xray 用户记得把文件放到 xray 文件夹），最后授予 v2ray/xray 可执行权限。

以下是用 bash 命令操作的示例（假设命令在 root 用户下运行）：

wget https://github.com/v2fly/v2ray-core/releases/latest/download/v2ray-linux-64.zip

unzip v2ray-linux-64.zip -d ./v2ray

sudo mkdir -p /usr/local/share/v2ray

sudo cp ./v2ray/*dat /usr/local/share/v2ray

sudo install -Dm755 ./v2ray/v2ray /usr/local/bin/v2ray
详细操作命令的步骤如下：


taiji@debian:~/下载$ wget https://github.com/v2fly/v2ray-core/releases/latest/download/v2ray-linux-64.zip
--2023-12-02 09:41:22--  https://github.com/v2fly/v2ray-core/releases/latest/download/v2ray-linux-64.zip
正在解析主机 github.com (github.com)... 20.205.243.166
正在连接 github.com (github.com)|20.205.243.166|:443... 已连接。已发出 HTTP 请求，正在等待回应... 302 Found
位置：https://github.com/v2fly/v2ray-core/releases/download/v5.12.1/v2ray-linux-64.zip [跟随至新的 URL]
--2023-12-02 09:41:24--  https://github.com/v2fly/v2ray-core/releases/download/v5.12.1/v2ray-linux-64.zip
再次使用存在的到 github.com:443 的连接。已发出 HTTP 请求，正在等待回应... 302 Found
位置：https://objects.githubusercontent.com/github-production-release-asset-2e65be/181461073/e1381378-51d2-41b8-a6a0-3d26708cb36b?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=AKIAIWNJYAX4CSVEH53A%2F20231202%2Fus-east-1%2Fs3%2Faws4_request&X-Amz-Date=20231202T013928Z&X-Amz-Expires=300&X-Amz-Signature=1329b32bbc67ba00916300f8407cbf7f3846572e283b4ab0270e4c466e048b3c&X-Amz-SignedHeaders=host&actor_id=0&key_id=0&repo_id=181461073&response-content-disposition=attachment%3B%20filename%3Dv2ray-linux-64.zip&response-content-type=application%2Foctet-stream [跟随至新的 URL]
--2023-12-02 09:41:25--  https://objects.githubusercontent.com/github-production-release-asset-2e65be/181461073/e1381378-51d2-41b8-a6a0-3d26708cb36b?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=AKIAIWNJYAX4CSVEH53A%2F20231202%2Fus-east-1%2Fs3%2Faws4_request&X-Amz-Date=20231202T013928Z&X-Amz-Expires=300&X-Amz-Signature=1329b32bbc67ba00916300f8407cbf7f3846572e283b4ab0270e4c466e048b3c&X-Amz-SignedHeaders=host&actor_id=0&key_id=0&repo_id=181461073&response-content-disposition=attachment%3B%20filename%3Dv2ray-linux-64.zip&response-content-type=application%2Foctet-stream
正在解析主机 objects.githubusercontent.com (objects.githubusercontent.com)... 185.199.109.133, 185.199.111.133, 185.199.110.133, ...
正在连接 objects.githubusercontent.com (objects.githubusercontent.com)|185.199.109.133|:443... 已连接。已发出 HTTP 请求，正在等待回应... 200 OK
长度：14411930 (14M) [application/octet-stream]
正在保存至: “v2ray-linux-64.zip”

v2ray-linux-64.zip          100%[=========================================>]  13.74M  18.9MB/s  用时 0.7s    

2023-12-02 09:41:28 (18.9 MB/s) - 已保存 “v2ray-linux-64.zip” [14411930/14411930])

taiji@debian:~/下载$ unzip v2ray-linux-64.zip -d ./v2ray
Archive:  v2ray-linux-64.zip
  inflating: ./v2ray/config.json     
  inflating: ./v2ray/geoip-only-cn-private.dat  
  inflating: ./v2ray/vpoint_vmess_freedom.json  
  inflating: ./v2ray/geoip.dat       
  inflating: ./v2ray/vpoint_socks_vmess.json  
  inflating: ./v2ray/v2ray           
  inflating: ./v2ray/geosite.dat     
   creating: ./v2ray/systemd/
   creating: ./v2ray/systemd/system/
  inflating: ./v2ray/systemd/system/v2ray.service  
  inflating: ./v2ray/systemd/system/v2ray@.service  

taiji@debian:~/下载$ sudo mkdir -p /usr/local/share/v2ray

[sudo] taiji 的密码：
taiji 不是 sudoers 文件。

taiji@debian:~/下载$ su
密码： 

root@debian:/home/taiji/下载# sudo mkdir -p /usr/local/share/v2ray

root@debian:/home/taiji/下载# sudo cp ./v2ray/*dat /usr/local/share/v2ray

root@debian:/home/taiji/下载# sudo install -Dm755 ./v2ray/v2ray /usr/local/bin/v2ray

root@debian:/home/taiji/下载# 
操作完以上步骤后，再打开v2rayA时，就可以正常使用了！