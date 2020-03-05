using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices.WindowsRuntime;
using Windows.Foundation;
using Windows.Foundation.Collections;
using Windows.UI.Xaml;
using Windows.UI.Xaml.Controls;
using Windows.UI.Xaml.Controls.Primitives;
using Windows.UI.Xaml.Data;
using Windows.UI.Xaml.Input;
using Windows.UI.Xaml.Media;
using Windows.UI.Xaml.Navigation;

using sdkrt;
using System.Text;
using System.Diagnostics;

//“空白页”项模板在 http://go.microsoft.com/fwlink/?LinkId=402352&clcid=0x409 上有介绍

namespace App1
{
    /// <summary>
    /// 可用于自身或导航至 Frame 内部的空白页。
    /// </summary>
    public sealed partial class MainPage : Page
    {
        sdkrt.ClassDeviceSDK classDeviceSDK;
        public MainPage()
        {
            Trace.WriteLine("start test");
            this.InitializeComponent();
            CS_Init();
        }

        private void CS_Init()
        {
            Trace.WriteLine("xxx Init sdk");
            classDeviceSDK = new sdkrt.ClassDeviceSDK();
            Trace.WriteLine("xxx set log");
            ClassDeviceSDK.callBackOnLog += (int level, string tag, string filename, int line, string funcname, string data) =>
            {
                StringBuilder sb = new StringBuilder();
                sb.Append("[").Append(level).Append("/").Append(tag).Append(" ").Append(filename).Append(" ").Append(line).
                Append(" ").Append(funcname).Append("] ").Append(data);
                Trace.WriteLine(sb.ToString());
                return 0;
            };
            Trace.WriteLine("xxx init call");
            int ret = classDeviceSDK._device_init("890d1af6be6cc5455261c5cfa8a2453d",
                "MEYCIQDzD4ty1TMn4IQ5LuzUUzofWbm7m3mg73GmWBNu4/e7aQIhAPKqcNz5JKuDdmouS1oc/OZdzfOb9iLRZ5ajjpsvabNX",
               "ilinkapp_060000873458be",
               30,2,1,0);
            if (ret == 0)
            {
                UInt64 uin = classDeviceSDK._device_get_uin();
                Trace.WriteLine("xxx 1");
                Trace.WriteLine(uin);
            }
            else
            {
                UInt64 uin = classDeviceSDK._device_get_uin();
                Trace.WriteLine("xxx 12");
                Trace.WriteLine(ret);
                Trace.WriteLine(uin);
            }
            ClassDeviceSDK.callBackOnLoginComplete += (err) =>
            {
                StringBuilder sb = new StringBuilder();
                sb.Append("callBackOnLoginComplete, err = ").Append(err);
                Trace.WriteLine(sb.ToString());
            };
        }

        private int ClassDeviceSDK_callBackOnLog(int level, string tag, string filename, int line, string funcname, string data)
        {
            throw new NotImplementedException();
        }
    }
}
