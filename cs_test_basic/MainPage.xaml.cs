using System;
using System.Diagnostics;
using System.Text;
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
//using UWPConsole;
using System.Threading;
using sdkrt;

// The Blank Page item template is documented at https://go.microsoft.com/fwlink/?LinkId=402352&clcid=0x409

namespace cs_test_basic
{
    /// <summary>
    /// An empty page that can be used on its own or navigated to within a Frame.
    /// </summary>
    public sealed partial class MainPage : Page
    {
        //WinRT_CPP.Class1 class1 = new WinRT_CPP.Class1();
        sdkrt.ClassDeviceSDK classDeviceSDK;
        
        public MainPage()
        {
            this.InitializeComponent();
            CS_Init();
        }

        private void CS_Init()
        {
            classDeviceSDK = new sdkrt.ClassDeviceSDK();
            //classDeviceSDK.Init();
            classDeviceSDK.Init(
                // din 144115192421795965
                //"704E20F220574ea9", "304402205A52184F973DFA6D8A9CC460D6CE86A260AF4727FD3A7E06F41E3B902164A9AD02207B4F3DA328F96E42C3D64934AC8EFD5AF8DA7618FAF03440E6C41148D9CCA65C", "0436D4DFBBD6586D2466465D1401771558BA0929C96883105701D30918A4A6088E9223022E5EEFC1DC3E6D23077D9E7D31", 2100002469, 1

                // din 144115192421796243
                "792EC7250E174269", 
                "3044022053F48912F6A5F2FF6571A120481AE64FD7BF2D5BBAA7D93D18BB80A3E882CB70022063F7C8A7308230C4F797F0EE2EE9E3D33DCF4C9D9018EEF99B454EB3C3DA070B", "0436D4DFBBD6586D2466465D1401771558BA0929C96883105701D30918A4A6088E9223022E5EEFC1DC3E6D23077D9E7D31", 
                2100002469, 
                1,
                tx_network_type_cs.network_type_wifi

                // din 144115192421796366
                //"871CBA36E93B4b32", "30440220537F889705CB0E93E1EA9B8C7C9502A5AD8CF914A61FE458B479D34508D3312F0220690625437C1E3A98A721107F5ACB01CE4B70934144F94A2F908AE0E9743BF70C", "0436D4DFBBD6586D2466465D1401771558BA0929C96883105701D30918A4A6088E9223022E5EEFC1DC3E6D23077D9E7D31", 2100002469, 1
                );
            sdkrt.ClassDeviceSDK.callBackOnStatus += (oldstatus, newstatus) =>
            {
                StringBuilder sb = new StringBuilder();
                sb.Append("called callBackOnStatus oldstatus").Append(oldstatus).Append(" newstatus ").Append(newstatus);
                UWPConsole.Console.WriteLine(sb.ToString());
            };
            //triggered by  classDeviceSDK.Init
            sdkrt.ClassDeviceSDK.callBackOnComplete += (n) =>
            {
                StringBuilder sb = new StringBuilder();
                sb.Append(n.ToString()).Append("called callBackOnComplete... ").Append(" with din ").Append(classDeviceSDK.tx_get_self_din_cs());
                UWPConsole.Console.WriteLine(sb.ToString());
            };
            /*classDeviceSDK.tx_set_log_func_cs();
            sdkrt.ClassDeviceSDK.callBackOnLog += (str) =>
             {
                 UWPConsole.Console.WriteLine("sdk log: " + str);
             };*/
            Thread.Sleep(5000);
            UWPConsole.Console.WriteLine("CS_Init done " );
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            StringBuilder result = new StringBuilder();
            //var nativeObject1 = new WinRT_CPP.Class1();
            /*WinRT_CPP.Class1.callBackTestEvent += (n) =>
            {
                result.Append(n.ToString()).Append(" callBackTestEvent ");
                //this.Result1.Text = result.ToString();
            };
            nativeObject1.ComputeResult(0);*/

        }

        private void Button_Click_1(object sender, RoutedEventArgs e)
        {

            // WriteAllText creates a file, writes the specified string to the file,
            // and then closes the file.    You do NOT need to call Flush() or Close().
            //System.IO.File.WriteAllText(@"C:\tmp\WriteText.txt", text);

            StringBuilder sb = new StringBuilder();
            // triggered by txca_request
            sdkrt.ClassDeviceSDK.callBackOnRequest += (voice_id, evt, state_info, state_info_tts, extend_state_info, extend_state_info_len) =>
            {
                sb.Append(state_info.GetSkillInfo().name).Append(" callBackOnRequest called");
                sb.Append("rsp txt " + state_info.Getrsp_text() + "GetLastSkillInfo " + state_info.GetLastSkillInfo().name);
                if (sdkrt.TXCA_EVENT_CS.txca_event_on_response == evt)
                {
                    for (int i = 0; i < state_info.Getresource_groups_size(); i++)
                    {
                        var grp = state_info.Getresource_groups().ElementAt(i);
                        for (int j = 0; j < grp.GetResourceSize(); j++)
                        {
                            sb.Append("format: ").Append(grp.GetResource().ElementAt(j).Getformat())
                            .Append(" id :").Append(grp.GetResource().ElementAt(j).Getid())
                            .Append(" content : ").Append(grp.GetResource().ElementAt(j).Getcontent()).Append("\n");
                            //.Append(" rsp:").Append(grp.GetResource().ElementAt(j).);
                        }
                    }

                    /*Debug.AutoFlush = true;
                    Debug.WriteLine(result.ToString());
                    Trace.AutoFlush = true;
                    Trace.WriteLine("Entering Main");*/
                    UWPConsole.Console.WriteLine(sb.ToString());
                }
                else if (sdkrt.TXCA_EVENT_CS.txca_event_on_tts == evt)
                {
                    uint len = state_info_tts.Getraw_data_len();
                    UWPConsole.Console.WriteLine("get data with length " + len);
                }
                else if (sdkrt.TXCA_EVENT_CS.txca_event_on_iot_info == evt)
                {
                    UWPConsole.Console.WriteLine("iot extend_state_info" + extend_state_info);
                    UWPConsole.Console.WriteLine("state_info name" + state_info.GetSkillInfo().name +
                        "state_info id" + state_info.GetSkillInfo().id +
                        "state_info response data" + state_info.Getresponse_data());

                }
                else
                {
                    sb.Append("status is ").Append(evt);
                    if (extend_state_info_len > 0)
                    {
                        sb.Append(extend_state_info).Append(" \n");
                    } else
                    {
                        sb.Append(" with empty extend_state_info").Append(" \n");
                    }
                    UWPConsole.Console.WriteLine(sb.ToString());
                }
            };
            //classDeviceSDK.txca_request_text("北京新闻");
            //classDeviceSDK.txca_request_text("放一首歌");
            /*String str = "";
            classDeviceSDK.txca_get_iot_device_list_cs(str);
            UWPConsole.Console.WriteLine("void " + str);*/
            //classDeviceSDK.txca_request_cs("hello");
            String voiceid = "";
            //sdkrt.TXCA_CHAT_TYPE_CS.txca_chat_via_voice;
            sdkrt.TXCA_PARAM_CONTEXT_CS  context_cs = new sdkrt.TXCA_PARAM_CONTEXT_CS();
            context_cs.Setsilent_timeout(500);
            context_cs.Setspeak_timeout(5000);
            context_cs.Setvoice_request_begin(true);
            context_cs.Setvoice_request_end(false);
            //context_cs.Setwakeup_type(TXCA_WAKEUP_TYPE_CS.txca_wakeup_type_local_with_text);
            //context_cs.Setwakeup_word("小微");
            //String request= ;
            //char[] request_chars = request.ToCharArray();
            classDeviceSDK.txca_request_text(voiceid, sdkrt.TXCA_CHAT_TYPE_CS.txca_chat_via_text, "放一首歌", context_cs);
            //classDeviceSDK.txca_request_text(voiceid, sdkrt.TXCA_CHAT_TYPE_CS.txca_chat_only_tts, "放一首歌", context_cs);
            //classDeviceSDK.txca_request_text(voiceid, sdkrt.TXCA_CHAT_TYPE_CS.txca_chat_via_text, "小微中国首都是哪里", context_cs);
           // classDeviceSDK.txca_request_text("我要听新闻");
            /*String request = "to be tested";
             byte[] request_byte = new byte[request.Length];
            for (int i =0; i < request.Length; i++)
            {
                request_byte[i] = (byte)request[i];
            }
            classDeviceSDK.txca_request_cs(voiceid, sdkrt.TXCA_CHAT_TYPE_CS.txca_chat_via_voice, request_byte,
                                     (uint) request.Length, context_cs);*/
            //nativeObject1.Init();
        }

        private void Button_Click_2(object sender, RoutedEventArgs e)
        {
            UWPConsole.Console.WriteLine("called UnInit");
            classDeviceSDK.UnInit();
            //m_objEngine.Uninit();
            //tx_exit_device();
        }

        private void Button_Click_3(object sender, RoutedEventArgs e)
        {
            sdkrt.ClassDeviceSDK.callBackOnEraseBinders += (n) =>
            {
                StringBuilder sb = new StringBuilder();
                sb.Append(n.ToString()).Append(" callBackOnEraseBinders... ");
                UWPConsole.Console.WriteLine(sb.ToString());
            };
            classDeviceSDK.tx_erase_all_binders_cs();
        }

        private void Button_Click_4(object sender, RoutedEventArgs e)
        {
            UWPConsole.Console.WriteLine("called getQRCodeUrl_cs");
            StringBuilder sb = new StringBuilder();
            string str = classDeviceSDK.getQRCodeUrl_cs();
            sb.Append("qrcode:").Append(str);
            UWPConsole.Console.WriteLine(sb.ToString());
        }

        private void Button_Click_5(object sender, RoutedEventArgs e)
        {
            UWPConsole.Console.WriteLine("call CS_Init");
            CS_Init();
        }

        private void Button_Click_6(object sender, RoutedEventArgs e)
        {
            ulong ull = classDeviceSDK.tx_get_self_din_cs();
            UWPConsole.Console.WriteLine("din:" + ull);
        }

        private void Button_Click_7(object sender, RoutedEventArgs e)
        {
            sdkrt.TXCA_PARAM_STATE_CS tpcs = new sdkrt.TXCA_PARAM_STATE_CS();
            tpcs.Setplay_id("test");
            tpcs.Setplay_mode(0);
            tpcs.Setplay_offset(0);
            tpcs.Setplay_state(0);
            TXCA_PARAM_SKILL_CS skillcs;
            skillcs.id = "id";
            skillcs.name= "name";
            skillcs.type = 0;
            tpcs.Setskill_info(skillcs);
            classDeviceSDK.txca_report_state_cs(tpcs);
        }

        private void Button1_Click(object sender, RoutedEventArgs e)
        {
            String voice_id = "";

            TXCA_PARAM_SKILL_CS skillcs;
            skillcs.id = "id";
            skillcs.name = "name";
            skillcs.type = 0;
            String[] play_ids = new String[2];
            play_ids[0] = "id0";
            play_ids[1] = "id1";
            int res = classDeviceSDK.txca_resource_get_detail_info_cs(voice_id, skillcs, play_ids, 2);
            UWPConsole.Console.WriteLine(" txca_resource_get_detail_info_cs " + res);
        }

        private void Button2_Click(object sender, RoutedEventArgs e)
        {
            string voice_id = "test";
            testtest(ref voice_id);
            TXCA_PARAM_SKILL_CS skillcs;
            skillcs.id = "id";
            skillcs.name = "name";
            skillcs.type = 0;
            int res = classDeviceSDK.txca_resource_set_favorite_cs(voice_id, skillcs, "playid", false);
            UWPConsole.Console.WriteLine(" txca_resource_set_favorite_cs " + res);
        }
        
        private void testtest(ref String str)
        {
            str = "1";
            str = "2";
            str = "3";
        }

        private void Button3_Click(object sender, RoutedEventArgs e)
        {

        }

        private void Button3_Click_1(object sender, RoutedEventArgs e)
        {
            sdkrt.TXCA_PARAM_STATE_CS state = new sdkrt.TXCA_PARAM_STATE_CS();
            state.Setplay_id("135");
            state.Setplay_mode(1);
            state.Setplay_content("content play");
            state.Setplay_state(1);
            sdkrt.TXCA_PARAM_SKILL_CS skill = new sdkrt.TXCA_PARAM_SKILL_CS();
            skill.name = "skillname135";
            skill.id = "skillid135";
            state.Setskill_info(skill);
            int res = classDeviceSDK.txca_report_state_cs(state);
            UWPConsole.Console.WriteLine("state " + res);
        }

        private void Button4_Click(object sender, RoutedEventArgs e)
        {
            for (int i = 0; i < 20; i++)
            {
                List<TX_BINDER_INFO_CS> list = new List<TX_BINDER_INFO_CS>();
                classDeviceSDK.tx_get_binder_list_cs(list);
                if (list.Count > 0)
                {
                    UWPConsole.Console.WriteLine("try time " + i + " got nickname " + list[0].Getnick_name());
                }
                else
                {
                    UWPConsole.Console.WriteLine("list empty at time " +i);
                }
            }
            
        }
    }
}