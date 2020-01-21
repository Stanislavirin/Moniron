

#include <gst/gst.h>
#include <glib.h>
#include <gst/rtsp-server/rtsp-server.h>
#include <gst/app/app.h>
#include <gst/video/videooverlay.h>
#include <QDebug>
#include <QFrame>

/* Structure to contain all our information, so we can pass it to callbacks */
typedef struct _CustomData {
  GstElement *pipeline;
  GstElement *RTPpipeline;
  GstElement *source;
  GstElement *tee;
  GstElement *d3dvideosink_queue;
  GstElement *rtsp_queue;
  GstElement *rtp_queue;
  GstElement *fakesink_queue;
  GstElement *videoxraw;
  GstElement *videoconvert;
  GstElement *videoconvert1;
  GstElement *videoconvert2;
  GstElement *x264enc;
  GstElement *openh264enc;
  GstElement *rtph264pay;
  GstElement *udpsink;
  GstElement *d3dvideosink;
  GstElement *appsink;
  GstElement *fakesink;
  GstElement *fakesrc;
  GstElement *appsrc;
  GstElement *sink;
  GstElement *filter;



} CustomData;

#include <QFrame>
#include <emitterclass.h>
//extern VideoStreamObject videostreamobject1;
extern EmitterClass b;

GMainLoop *loop;

//запуск видеострима
void  rtsp_server_start(WId widgetID)
{


    //---------------------------------------------------------------------------------------


    GstPad *tee_d3dvideosink_pad, *tee_rtp_pad, *queue_d3dvideosink_pad, *queue_rtp_pad;
    GstPad *tee_fakesink_pad, *queue_fakesink_pad, *fakesrc_pad, *padx;
    int ret;
    CustomData data;

    GstRTSPServer *server;
    GstRTSPMountPoints *mounts;
    GstRTSPMediaFactory *factory;

    GstBus *bus;
    GstMessage *msg;

    gst_init (NULL, NULL);

    loop = g_main_loop_new (NULL, FALSE);

    /* create a server instance */
    server = gst_rtsp_server_new ();

    /* get the mount points for this server, every server has a default object
           * that be used to map uri mount points to media factories */
    mounts = gst_rtsp_server_get_mount_points (server);



    data.pipeline = gst_pipeline_new ("playall");
    data.source = gst_element_factory_make ("ksvideosrc", "ksvideosrc1");  //ksvideosrc   videotestsrc

    data.filter = gst_element_factory_make("capsfilter","filter");

    data.videoconvert = gst_element_factory_make ("videoconvert", "videoconvert1");

    data.tee = gst_element_factory_make ("tee", "tee1");

    data.d3dvideosink_queue=gst_element_factory_make ("queue", "queue1");
    data.d3dvideosink = gst_element_factory_make ("d3dvideosink", "d3dvideosink1");
    data.rtp_queue = gst_element_factory_make ("queue", "queue2");
    data.openh264enc = gst_element_factory_make ("openh264enc", "openh264enc1");
    data.rtph264pay = gst_element_factory_make ("rtph264pay", "rtph264pay1");
    data.udpsink = gst_element_factory_make ("udpsink", "udpsink1");






    g_object_set (data.rtph264pay , "config-interval", 10, "pt", 96, NULL);
    g_object_set (data.udpsink , "host", "127.0.0.1", "port", 5000,NULL);

    if (!data.pipeline  || !data.source || !data.filter || !data.videoconvert || !data.tee || !data.d3dvideosink_queue  || !data.d3dvideosink ||
              !data.rtp_queue || !data.openh264enc || !data.rtph264pay || !data.udpsink ) {
        g_printerr ("Not all elements could be created.\n");
    }
    gst_video_overlay_set_window_handle(GST_VIDEO_OVERLAY(data.d3dvideosink), widgetID);

    gst_bin_add_many (GST_BIN (data.pipeline), data.source, data.filter,data.videoconvert, data.tee, data.d3dvideosink_queue, data.d3dvideosink,
                                               data.rtp_queue, data.openh264enc, data.rtph264pay, data.udpsink,NULL);



    if (gst_element_link_many(data.source, data.filter,data.videoconvert,data.tee, NULL) != TRUE ||
            gst_element_link_many(data.d3dvideosink_queue, data.d3dvideosink, NULL) != TRUE ||
            gst_element_link_many (data.rtp_queue, data.openh264enc, data.rtph264pay, data.udpsink, NULL) != TRUE ) {
        g_printerr ("Elements could not be linked.\n");
        gst_object_unref (data.pipeline);
    }

    GstCaps *Cap;
    Cap = gst_caps_from_string("video/x-raw, width=1280, height=720,framerate=9/1");

    g_object_set(data.filter,"caps",Cap,NULL);

    ret = gst_element_set_state (data.pipeline, GST_STATE_PLAYING);
          if (ret == GST_STATE_CHANGE_FAILURE) {
              g_printerr ("Unable to set the pipeline to the playing state.\n");
              gst_object_unref (data.pipeline);
          }






    /* Manually link the Tee, which has "Request" pads */
    tee_d3dvideosink_pad = gst_element_get_request_pad (data.tee, "src_%u");
    queue_d3dvideosink_pad = gst_element_get_static_pad (data.d3dvideosink_queue, "sink");
    tee_rtp_pad = gst_element_get_request_pad (data.tee, "src_%u");
    queue_rtp_pad = gst_element_get_static_pad (data.rtp_queue, "sink");
    if (gst_pad_link (tee_d3dvideosink_pad, queue_d3dvideosink_pad) != GST_PAD_LINK_OK ||
        gst_pad_link (tee_rtp_pad, queue_rtp_pad) != GST_PAD_LINK_OK )
    {
        g_printerr ("Tee could not be linked\n");
        gst_object_unref (data.pipeline);
    }

    gst_object_unref (queue_d3dvideosink_pad);
    gst_object_unref (queue_rtp_pad);












//------------------------------------------------------------------------


//    gst_element_set_state (data.pipeline, GST_STATE_PAUSED);
//    gst_element_set_state (data.fakesink, GST_STATE_PAUSED);

//    if (gst_pad_link (tee_d3dvideosink_pad, queue_d3dvideosink_pad) != GST_PAD_LINK_OK ||
//        gst_pad_link (tee_rtp_pad, queue_fakesink_pad ) != GST_PAD_LINK_OK   ||
//        gst_pad_link (tee_fakesink_pad, queue_rtp_pad) != GST_PAD_LINK_OK) {
//        g_printerr ("Tee could not be linked\n");
//        gst_object_unref (data.pipeline);
//    }

//    gst_element_set_state (data.pipeline, GST_STATE_PLAYING);
//    gst_element_set_state (data.fakesink, GST_STATE_PLAYING);







//    /* Wait until error or EOS */
//     bus = gst_element_get_bus (data.pipeline);
//     msg = gst_bus_timed_pop_filtered (bus, GST_CLOCK_TIME_NONE, GstMessageType(GST_MESSAGE_ERROR | GST_MESSAGE_EOS));

//     /* Release the request pads from the Tee, and unref them */
//     gst_element_release_request_pad (data.tee, tee_d3dvideosink_pad);
//     gst_element_release_request_pad (data.tee, tee_rtp_pad);
//     gst_object_unref (tee_d3dvideosink_pad);
//     gst_object_unref (tee_rtp_pad);

//     /* Free resources */
//     if (msg != NULL)
//       gst_message_unref (msg);
//     gst_object_unref (bus);
//     gst_element_set_state (data.pipeline, GST_STATE_NULL);

//     gst_object_unref (data.pipeline);

}

//остановить стрим
void rtsp_stop()
{
    g_main_loop_quit(loop);
}

//возобновить стрим
void rtsp_play()
{
    g_main_loop_run(loop);
}



//gst-device-monitor-1.0

//Device found:

//        name  : HD USB Camera
//        class : Video/Source
//        caps  : image/jpeg, width=(int)1920, height=(int)1080, framerate=(fraction)30/1, pixel-aspect-ratio=(fraction)1/1;
//                image/jpeg, width=(int)1280, height=(int)720, framerate=(fraction)60/1, pixel-aspect-ratio=(fraction)1/1;
//                image/jpeg, width=(int)1024, height=(int)768, framerate=(fraction)30/1, pixel-aspect-ratio=(fraction)1/1;
//                image/jpeg, width=(int)640, height=(int)480, framerate=(fraction)601/5, pixel-aspect-ratio=(fraction)1/1;
//                image/jpeg, width=(int)800, height=(int)600, framerate=(fraction)60/1, pixel-aspect-ratio=(fraction)1/1;                image/jpeg, width=(int)1280, height=(int)1024, framerate=(fraction)30/1, pixel-aspect-ratio=(fraction)12/11;
//                image/jpeg, width=(int)320, height=(int)240, framerate=(fraction)601/5, pixel-aspect-ratio=(fraction)1/1;
//                video/x-raw, format=(string)YUY2, width=(int)1920, height=(int)1080, framerate=(fraction)6/1, pixel-aspect-ratio=(fraction)1/1;
//                video/x-raw, format=(string)YUY2, width=(int)1280, height=(int)720, framerate=(fraction)9/1, pixel-aspect-ratio=(fraction)1/1;
//                video/x-raw, format=(string)YUY2, width=(int)1024, height=(int)768, framerate=(fraction)6/1, pixel-aspect-ratio=(fraction)1/1;
//                video/x-raw, format=(string)YUY2, width=(int)640, height=(int)480, framerate=(fraction)30/1, pixel-aspect-ratio=(fraction)1/1;
//                video/x-raw, format=(string)YUY2, width=(int)800, height=(int)600, framerate=(fraction)20/1, pixel-aspect-ratio=(fraction)1/1;
//                video/x-raw, format=(string)YUY2, width=(int)1280, height=(int)1024, framerate=(fraction)6/1, pixel-aspect-ratio=(fraction)12/11;
//                video/x-raw, format=(string)YUY2, width=(int)320, height=(int)240, framerate=(fraction)30/1, pixel-aspect-ratio=(fraction)1/1;
//        gst-launch-1.0 ksvideosrc device-path="\\\\\?\\usb\#vid_05a3\&pid_9230\&mi_00\#6\&3c0978f\&0\&0000\#\{6994ad05-93ef-11d0-a3cc-00a0c9223196\}\\global" ! ...
