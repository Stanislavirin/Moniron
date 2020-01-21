#include "gstreamer_example.h"
#include <QDebug>
#include <QWidget>

#include <glib.h>
#include <gst/gst.h>
#include <gst/video/videooverlay.h>
//#include <gst/rtsp-server/rtsp-server.h>

/* Structure to contain all our information, so we can pass it to callbacks */
typedef struct _CustomData {
  GstElement *pipeline;
  GstElement *source;
  GstElement *tee;
  GstElement *overlay_queue;
  GstElement *rtsp_queue;
  GstElement *videoxraw;
  GstElement *videoconvert;
  GstElement *x264enc;
  GstElement *rtph264pay;
  GstElement *sink;
} CustomData;

/* Handler for the pad-added signal */
//static void pad_added_handler (GstElement *src, GstPad *pad, CustomData *data);


void example_run(QWidget *widget) {

//    GstRTSPServer *server;
//    GstRTSPMountPoints *mounts;
//    GstRTSPMediaFactory *factory;

//    CustomData data;
//    int ret;
////    /* Initialize GStreamer */
//    gst_init (NULL, NULL);



//    data.pipeline = gst_pipeline_new ("xvoverlay");
//    data.source = gst_element_factory_make ("ksvideosrc", NULL);
//    data.sink = gst_element_factory_make ("d3dvideosink", NULL);
//    gst_bin_add_many (GST_BIN (data.pipeline), data.source, data.sink, NULL);
//    gst_element_link (data.source, data.sink);


//    gst_video_overlay_set_window_handle(GST_VIDEO_OVERLAY(data.sink), widget->winId());


//    ret = gst_element_set_state (data.pipeline, GST_STATE_PLAYING);
//    if (ret == GST_STATE_CHANGE_FAILURE) {
//        g_printerr ("Unable to set the pipeline to the playing state.\n");
//        gst_object_unref (data.pipeline);
//    }

//--------------------------------------------------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------------------------------------------------




//      /* Build the pipeline. Note that we are NOT linking the source at this
//       * point. We will do it later. */
//      gst_bin_add_many (GST_BIN (data.pipeline), data.source, data.convert , data.sink, NULL);
//      if (!gst_element_link (data.convert, data.sink)) {
//        g_printerr ("Elements could not be linked.\n");
//        gst_object_unref (data.pipeline);
//        //return -1;
//      }

//      /* Set the URI to play */
//      g_object_set (data.source, "uri", "https://www.freedesktop.org/software/gstreamer-sdk/data/media/sintel_trailer-480p.webm", NULL);

//      /* Connect to the pad-added signal */
//      g_signal_connect (data.source, "pad-added", G_CALLBACK (pad_added_handler), &data);


//      gst_video_overlay_set_window_handle(GST_VIDEO_OVERLAY(data.convert), widget->winId())
//              ;
//      /* Start playing */
//      ret = gst_element_set_state (data.pipeline, GST_STATE_PLAYING);
//      if (ret == GST_STATE_CHANGE_FAILURE) {
//        g_printerr ("Unable to set the pipeline to the playing state.\n");
//        gst_object_unref (data.pipeline);
//        //return -1;
//      }

//      /* Listen to the bus */
//      bus = gst_element_get_bus (data.pipeline);
//      do {
//        msg = gst_bus_timed_pop_filtered (bus, GST_CLOCK_TIME_NONE,
//            GstMessageType ( GST_MESSAGE_STATE_CHANGED | GST_MESSAGE_ERROR | GST_MESSAGE_EOS));

//        /* Parse message */
//        if (msg != NULL) {
//          GError *err;
//          gchar *debug_info;

//          switch (GST_MESSAGE_TYPE (msg)) {
//            case GST_MESSAGE_ERROR:
//              gst_message_parse_error (msg, &err, &debug_info);
//              g_printerr ("Error received from element %s: %s\n", GST_OBJECT_NAME (msg->src), err->message);
//              g_printerr ("Debugging information: %s\n", debug_info ? debug_info : "none");
//              g_clear_error (&err);
//              g_free (debug_info);
//              terminate = TRUE;
//              break;
//            case GST_MESSAGE_EOS:
//              g_print ("End-Of-Stream reached.\n");
//              terminate = TRUE;
//              break;
//            case GST_MESSAGE_STATE_CHANGED:
//              /* We are only interested in state-changed messages from the pipeline */
//              if (GST_MESSAGE_SRC (msg) == GST_OBJECT (data.pipeline)) {
//                GstState old_state, new_state, pending_state;
//                gst_message_parse_state_changed (msg, &old_state, &new_state, &pending_state);
//                g_print ("Pipeline state changed from %s to %s:\n",
//                    gst_element_state_get_name (old_state), gst_element_state_get_name (new_state));
//              }
//              break;
//            default:
//              /* We should not reach here */
//              g_printerr ("Unexpected message received.\n");
//              break;
//          }
//          gst_message_unref (msg);
//        }
//      } while (!terminate);

//      /* Free resources */
//      gst_object_unref (bus);
//      gst_element_set_state (data.pipeline, GST_STATE_NULL);
//      gst_object_unref (data.pipeline);
//      //return 0;





//    CustomData data;
//    int ret;
//    /* Initialize GStreamer */
//    gst_init (NULL, NULL);



//    data.pipeline = gst_pipeline_new ("xvoverlay");
//    data.source = gst_element_factory_make ("ksvideosrc", NULL);
//    data.sink = gst_element_factory_make ("d3dvideosink", NULL);
//    gst_bin_add_many (GST_BIN (data.pipeline), data.source, data.sink, NULL);
//    gst_element_link (data.source, data.sink);


//    gst_video_overlay_set_window_handle(GST_VIDEO_OVERLAY(data.sink), widget->winId());


//    ret = gst_element_set_state (data.pipeline, GST_STATE_PLAYING);
//    if (ret == GST_STATE_CHANGE_FAILURE) {
//        g_printerr ("Unable to set the pipeline to the playing state.\n");
//        gst_object_unref (data.pipeline);
//    }





}

///* This function will be called by the pad-added signal */
//static void pad_added_handler (GstElement *src, GstPad *new_pad, CustomData *data) {
//  GstPad *sink_pad = gst_element_get_static_pad (data->convert, "sink");
//  GstPadLinkReturn ret;
//  GstCaps *new_pad_caps = NULL;
//  GstStructure *new_pad_struct = NULL;
//  const gchar *new_pad_type = NULL;

//  g_print ("Received new pad '%s' from '%s':\n", GST_PAD_NAME (new_pad), GST_ELEMENT_NAME (src));

//  /* If our converter is already linked, we have nothing to do here */
//  if (gst_pad_is_linked (sink_pad)) {
//    g_print ("We are already linked. Ignoring.\n");
//    goto exit;
//  }

//  /* Check the new pad's type */
//  new_pad_caps = gst_pad_get_current_caps (new_pad);
//  new_pad_struct = gst_caps_get_structure (new_pad_caps, 0);
//  new_pad_type = gst_structure_get_name (new_pad_struct);
//  if (!g_str_has_prefix (new_pad_type, "video/x-raw")) {
//    g_print ("It has type '%s' which is not raw audio. Ignoring.\n", new_pad_type);
//    goto exit;
//  }

//  /* Attempt the link */
//  ret = gst_pad_link (new_pad, sink_pad);
//  if (GST_PAD_LINK_FAILED (ret)) {
//    g_print ("Type is '%s' but link failed.\n", new_pad_type);
//  } else {
//    g_print ("Link succeeded (type '%s').\n", new_pad_type);
//  }

//exit:
//  /* Unreference the new pad's caps, if we got them */
//  if (new_pad_caps != NULL)
//    gst_caps_unref (new_pad_caps);

//  /* Unreference the sink pad */
//  gst_object_unref (sink_pad);
//}



//--------------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------------


//#include <gst/gst.h>
//#include <glib.h>
//#include <gst/rtsp-server/rtsp-server.h>
//#include <gst/app/app.h>
//#include <gst/video/videooverlay.h>
////#include <videostreamobject.h>

//// /* Structure to contain all our information, so we can pass it to callbacks */
////typedef struct _CustomData {
////    GstElement *pipeline;
////    GstElement *source;
////    GstElement *convert;
////    GstElement *sink;
////} CustomData;



///* Structure to contain all our information, so we can pass it to callbacks */
//typedef struct _CustomData {
//  GstElement *pipeline;
//  GstElement *source;
//  GstElement *tee;
//  GstElement *d3dvideosink_queue;
//  GstElement *rtsp_queue;
//  GstElement *videoxraw;
//  GstElement *videoconvert;
//  GstElement *x264enc;
//  GstElement *rtph264pay;
//  GstElement *d3dvideosink;
//  GstElement *appsink;
//  GstElement *fakesink;
//  GstElement *appsrc;
//  GstElement *sink;
//} CustomData;

//typedef struct
//{
//  GstElement *generator_pipe;
//  GstElement *vid_appsink;
//  GstElement *vid_appsrc;
//  GstElement *aud_appsink;
//  GstElement *aud_appsrc;
//} MyContext;

//static void
//ctx_free (MyContext * ctx)
//{
//  gst_element_set_state (ctx->generator_pipe, GST_STATE_NULL);

//  gst_object_unref (ctx->generator_pipe);
//  gst_object_unref (ctx->vid_appsrc);
//  gst_object_unref (ctx->vid_appsink);
//  gst_object_unref (ctx->aud_appsrc);
//  gst_object_unref (ctx->aud_appsink);

//  g_free (ctx);
//}


///* called when we need to give data to an appsrc */
////static void
////new_sample (GstElement * appsrc, guint unused, MyContext * ctx)
///* The appsink has received a buffer */
////static GstFlowReturn new_sample (GstElement *sink, MyContext * ctx) {
////  GstSample *sample;
////  g_print ("--");
////  /* Retrieve the buffer */
////  g_signal_emit_by_name (sink, "pull-sample", &sample);
////  if (sample) {
////    /* The only thing we do in this example is print a * to indicate a received buffer */
////    g_print ("*");
////    gst_sample_unref (sample);
////    return GST_FLOW_OK;
////  }
////  return GST_FLOW_ERROR;
////}

////#include <QtCore>
////#include <QApplication>
////#include <QWidget>
//#include <QFrame>
//#include <emitterclass.h>
////extern VideoStreamObject videostreamobject1;
//extern EmitterClass b;
//#include <QDebug>
///* called when a new media pipeline is constructed. We can query the
// * pipeline and configure our appsrc */
////static void
////media_constructed (GstRTSPMediaFactory * factory, GstRTSPMedia * media,
////    gpointer user_data)
////{
////    GstElement *element, *appsrc, *appsink, *queuesrc ,* pipeline, *sink;
////    GstCaps *caps;
////    MyContext *ctx;
////    g_print ("We are in callback\n");
////    //QWidget *widjet;

////   // widjet=b.frame;
////    element = gst_rtsp_media_get_element (media);

////    appsink = gst_bin_get_by_name_recurse_up (GST_BIN (element), "d3dvideosink0");
////    gst_video_overlay_set_window_handle(GST_VIDEO_OVERLAY(appsink), b.widgetID);

////}











///* called when we need to give data to an appsrc */
//static void
//need_data (GstElement * appsrc, guint unused, MyContext * ctx)
//{
//  GstSample *sample;
//  GstFlowReturn ret;

//  if (appsrc == ctx->vid_appsrc)
//    sample = gst_app_sink_pull_sample (GST_APP_SINK (ctx->vid_appsink));
//  else
//    sample = gst_app_sink_pull_sample (GST_APP_SINK (ctx->aud_appsink));

//  if (sample) {
//    GstBuffer *buffer = gst_sample_get_buffer (sample);
//    GstSegment *seg = gst_sample_get_segment (sample);
//    GstClockTime pts, dts;

//    /* Convert the PTS/DTS to running time so they start from 0 */
//    pts = GST_BUFFER_PTS (buffer);
//    if (GST_CLOCK_TIME_IS_VALID (pts))
//      pts = gst_segment_to_running_time (seg, GST_FORMAT_TIME, pts);

//    dts = GST_BUFFER_DTS (buffer);
//    if (GST_CLOCK_TIME_IS_VALID (dts))
//      dts = gst_segment_to_running_time (seg, GST_FORMAT_TIME, dts);

//    if (buffer) {
//      /* Make writable so we can adjust the timestamps */
//      buffer = gst_buffer_copy (buffer);
//      GST_BUFFER_PTS (buffer) = pts;
//      GST_BUFFER_DTS (buffer) = dts;
//      g_signal_emit_by_name (appsrc, "push-buffer", buffer, &ret);
//    }

//    /* we don't need the appsink sample anymore */
//    gst_sample_unref (sample);
//  }
//}



///* called when a new media pipeline is constructed. We can query the
// * pipeline and configure our appsrc */
//static void
//media_configure (GstRTSPMediaFactory * factory, GstRTSPMedia * media,
//    gpointer user_data)
//{
//  GstElement *element, *appsrc, *appsink;
//  GstCaps *caps;
//  MyContext *ctx;

//  ctx = g_new0 (MyContext, 1);
//  /* This pipeline generates H264 video and PCM audio. The appsinks are kept small so that if delivery is slow,
//   * encoded buffers are dropped as needed. There's slightly more buffers (32) allowed for audio */
//  ctx->generator_pipe =
//      gst_parse_launch
////         ksvideosrc   //video/x-raw, format=(string)I420, width=(int)1280, height=(int)720, framerate=(fraction)30/1 , ! videoconvert ! x264enc pass=qual quantizer=20 tune=zerolatency !

////          ("videotestsrc is-live=true ! video/x-raw, format=(string)I420, width=(int)1280, height=(int)720, framerate=(fraction)30/1 ! x264enc speed-preset=superfast tune=zerolatency ! video/x-h264, format=(string)I420, width=(int)1280, height=(int)720, stream-format=byte-stream! h264parse ! appsink name=vid max-buffers=1 drop=true "
////           "audiotestsrc is-live=true ! appsink name=aud max-buffers=32 drop=true",


////         ("videotestsrc is-live=true  ! video/x-raw, format=(string)I420 ,width=(int)1280, height=(int)720, framerate=(fraction)30/1 ! x264enc speed-preset=superfast tune=zerolatency ! h264parse ! appsink name=vid max-buffers=1 drop=true "
////          "audiotestsrc is-live=true ! appsink name=aud max-buffers=32 drop=true",

//          ("videotestsrc is-live=true ! x264enc speed-preset=superfast tune=zerolatency ! h264parse ! appsink name=vid max-buffers=1 drop=true "
//                "audiotestsrc is-live=true ! appsink name=aud max-buffers=32 drop=true",
//                NULL);

//  /* make sure the data is freed when the media is gone */
//  g_object_set_data_full (G_OBJECT (media), "rtsp-extra-data", ctx,
//      (GDestroyNotify) ctx_free);

//  /* get the element (bin) used for providing the streams of the media */
//  element = gst_rtsp_media_get_element (media);

//  /* Find the 2 app sources (video / audio), and configure them, connect to the
//   * signals to request data */
//  /* configure the caps of the video */
//    caps = gst_caps_new_simple ("video/x-h264",
//        "stream-format", G_TYPE_STRING, "byte-stream",
////        "alignment", G_TYPE_STRING, "au",
////        "width", G_TYPE_INT, 1280, "height", G_TYPE_INT, 720,
//        /*"framerate", GST_TYPE_FRACTION, 30, 1,*/ NULL);

////  caps = gst_caps_new_simple ("video/x-h264",
////      "stream-format", G_TYPE_STRING, "byte-stream",
////      "alignment", G_TYPE_STRING, "au",
////      "width", G_TYPE_INT, 1280, "height", G_TYPE_INT, 720,
////      "framerate", GST_TYPE_FRACTION, 30, 1, NULL);
//    ctx->vid_appsrc = appsrc =
//            gst_bin_get_by_name_recurse_up (GST_BIN (element), "videosrc");
//    ctx->vid_appsink = appsink =
//            gst_bin_get_by_name (GST_BIN (ctx->generator_pipe), "vid");
//    gst_util_set_object_arg (G_OBJECT (appsrc), "format", "time");
//    g_object_set (G_OBJECT (appsrc), "caps", caps, NULL);
//    g_object_set (G_OBJECT (appsink), "caps", caps, NULL);
//    /* install the callback that will be called when a buffer is needed */
//    g_signal_connect (appsrc, "need-data", (GCallback) need_data, ctx);
//    gst_caps_unref (caps);

//    caps = gst_caps_new_simple ("audio/x-raw", "format", G_TYPE_STRING, "S24BE",
//                                "layout", G_TYPE_STRING, "interleaved", "rate", G_TYPE_INT, 48000,
//                                "channels", G_TYPE_INT, 2, NULL);
//    ctx->aud_appsrc = appsrc =
//            gst_bin_get_by_name_recurse_up (GST_BIN (element), "audiosrc");
//    ctx->aud_appsink = appsink =
//            gst_bin_get_by_name (GST_BIN (ctx->generator_pipe), "aud");
//    gst_util_set_object_arg (G_OBJECT (appsrc), "format", "time");
//    g_object_set (G_OBJECT (appsrc), "caps", caps, NULL);
//    g_object_set (G_OBJECT (appsink), "caps", caps, NULL);
//    g_signal_connect (appsrc, "need-data", (GCallback) need_data, ctx);
//    gst_caps_unref (caps);

//    gst_element_set_state (ctx->generator_pipe, GST_STATE_PLAYING);
//    gst_object_unref (element);
//}






//GMainLoop *loop;

////запуск видеострима
//void  rtsp_server_start(WId widgetID)
//{









////      GstPad *tee_d3dvideosink_pad, *tee_rtsp_pad, *queue_d3dvideosink_pad, *queue_rtsp_pad;
////      int ret;
////      CustomData data;

////      GstRTSPServer *server;
////      GstRTSPMountPoints *mounts;
////      GstRTSPMediaFactory *factory;

////      gst_init (NULL, NULL);

////      loop = g_main_loop_new (NULL, FALSE);

////      /* create a server instance */
////      server = gst_rtsp_server_new ();

////      /* get the mount points for this server, every server has a default object
////       * that be used to map uri mount points to media factories */
////      mounts = gst_rtsp_server_get_mount_points (server);



////      data.pipeline = gst_pipeline_new ("xvoverlay");
////      data.source = gst_element_factory_make ("videotestsrc", "camerasrc");  //ksvideosrc   videotestsrc
////      data.tee = gst_element_factory_make ("tee", "tee");
////      data.d3dvideosink_queue=gst_element_factory_make ("queue", "d3dvideosink_queue");
////      data.d3dvideosink = gst_element_factory_make ("d3dvideosink", "d3dvideosink");
////      data.rtsp_queue = gst_element_factory_make ("queue", "rtsp_queue");
////      data.appsrc = gst_element_factory_make ("appsrc", "videosrc");


////      if (!data.pipeline || !data.source || !data.tee || !data.d3dvideosink_queue || !data.d3dvideosink ||
////              !data.rtsp_queue ) {
////          g_printerr ("Not all elements could be created.\n");
////      }

////      gst_video_overlay_set_window_handle(GST_VIDEO_OVERLAY(data.d3dvideosink), widgetID); // сливаем на виджет


////      gst_bin_add_many (GST_BIN (data.pipeline), data.source, data.tee, data.d3dvideosink_queue, data.d3dvideosink, data.rtsp_queue, data.appsrc, NULL);
////      if (gst_element_link_many (data.source, data.tee, NULL) != TRUE ||
////          gst_element_link_many (data.d3dvideosink_queue, data.d3dvideosink, NULL) != TRUE ||
////          gst_element_link_many (data.rtsp_queue, data.appsrc, NULL) != TRUE ) {
////          g_printerr ("Elements could not be linked.\n");
////          gst_object_unref (data.pipeline);
////      }

////      /* Manually link the Tee, which has "Request" pads */
////      tee_d3dvideosink_pad = gst_element_get_request_pad (data.tee, "src_%u");
////      g_print ("Obtained request pad %s for d3dvideosink branch.\n", gst_pad_get_name (tee_d3dvideosink_pad));
////      tee_rtsp_pad = gst_element_get_request_pad (data.tee, "src_%u");
////      g_print ("Obtained request pad %s for rtsp branch.\n", gst_pad_get_name (tee_rtsp_pad));
////      queue_d3dvideosink_pad = gst_element_get_static_pad (data.d3dvideosink_queue, "sink");
////      queue_rtsp_pad = gst_element_get_static_pad (data.rtsp_queue, "sink");
////      if (gst_pad_link (tee_d3dvideosink_pad, queue_d3dvideosink_pad) != GST_PAD_LINK_OK ||
////          gst_pad_link (tee_rtsp_pad, queue_rtsp_pad) != GST_PAD_LINK_OK ) {
////          g_printerr ("Tee could not be linked\n");
////          gst_object_unref (data.pipeline);
////      }
////      gst_object_unref (queue_d3dvideosink_pad);
////      gst_object_unref (queue_rtsp_pad);


////      ret = gst_element_set_state (data.pipeline, GST_STATE_PLAYING);
////      if (ret == GST_STATE_CHANGE_FAILURE) {
////          g_printerr ("Unable to set the pipeline to the playing state.\n");
////          gst_object_unref (data.pipeline);
////      }






////      /* make a media factory for a test stream. The default media factory can use
////       * gst-launch syntax to create pipelines.
////       * any launch line works as long as it contains elements named pay%d. Each
////       * element with pay%d names will be a stream */
////      factory = gst_rtsp_media_factory_new ();
////      gst_rtsp_media_factory_set_launch (factory,
////           "( appsrc name=videosrc ! h264parse ! rtph264pay name=pay0 pt=96 "
////           "  appsrc name=audiosrc ! audioconvert ! rtpL24pay name=pay1 pt=97 )");

////      /* notify when our media is ready, This is called whenever someone asks for
////       * the media and a new pipeline with our appsrc is created */
////      g_signal_connect (factory, "media-configure", (GCallback) media_configure,
////          NULL);


////      GstElement *element, *appsrc, *appsink;
////      GstCaps *caps;
////      MyContext *ctx;

////      ctx = g_new0 (MyContext, 1);
////      /* This pipeline generates H264 video and PCM audio. The appsinks are kept small so that if delivery is slow,
////       * encoded buffers are dropped as needed. There's slightly more buffers (32) allowed for audio */
////      ctx->generator_pipe =
////          gst_parse_launch
////    //         ksvideosrc   //video/x-raw, format=(string)I420, width=(int)1280, height=(int)720, framerate=(fraction)30/1 , ! videoconvert ! x264enc pass=qual quantizer=20 tune=zerolatency !

////    //          ("videotestsrc is-live=true ! video/x-raw, format=(string)I420, width=(int)1280, height=(int)720, framerate=(fraction)30/1 ! x264enc speed-preset=superfast tune=zerolatency ! video/x-h264, format=(string)I420, width=(int)1280, height=(int)720, stream-format=byte-stream! h264parse ! appsink name=vid max-buffers=1 drop=true "
////    //           "audiotestsrc is-live=true ! appsink name=aud max-buffers=32 drop=true",


////    //         ("videotestsrc is-live=true  ! video/x-raw, format=(string)I420 ,width=(int)1280, height=(int)720, framerate=(fraction)30/1 ! x264enc speed-preset=superfast tune=zerolatency ! h264parse ! appsink name=vid max-buffers=1 drop=true "
////    //          "audiotestsrc is-live=true ! appsink name=aud max-buffers=32 drop=true",

////              ("videotestsrc is-live=true ! x264enc speed-preset=superfast tune=zerolatency ! h264parse ! appsink name=vid max-buffers=1 drop=true "
////                    "audiotestsrc is-live=true ! appsink name=aud max-buffers=32 drop=true",
////                    NULL);






////      /* attach the test factory to the /test url */
////      gst_rtsp_mount_points_add_factory (mounts, "/test", factory);

////      /* don't need the ref to the mounts anymore */
////      g_object_unref (mounts);

////      /* attach the server to the default maincontext */
////      gst_rtsp_server_attach (server, NULL);

////      /* start serving */
////      g_print ("stream ready at rtsp://127.0.0.1:8554/test\n");
////      g_main_loop_run (loop);





































////        CustomData data;
////        GstRTSPServer *server;
////        GstRTSPMountPoints *mounts;
////        GstRTSPMediaFactory *factory;
////        GstPad *tee_overlay_pad, *tee_rtsp_pad;
////        GstPad *queue_overlay_pad, *queue_rtsp_pad;
////        GstBus *bus;
////        GstMessage *msg;

////      gst_init (NULL, NULL);

////      loop = g_main_loop_new (NULL, FALSE);

////      /* create a server instance */
////      server = gst_rtsp_server_new ();

////      /* get the mount points for this server, every server has a default object
////       * that be used to map uri mount points to media factories */
////      mounts = gst_rtsp_server_get_mount_points (server);

////      /* make a media factory for a test stream. The default media factory can use
////       * gst-launch syntax to create pipelines.
////       * any launch line works as long as it contains elements named pay%d. Each
////       * element with pay%d names will be a stream */
////      factory = gst_rtsp_media_factory_new ();
////      gst_rtsp_media_factory_set_launch (factory,
////          "( ksvideosrc ! tee name=t !"

////          //"queue ! video/x-raw, framerate=(fraction)30/1 ! x264enc pass=qual quantizer=20 tune=zerolatency ! "
////          "queue ! video/x-raw, format=(string)I420, width=(int)1280, height=(int)720, framerate=(fraction)30/1 ! videoconvert ! x264enc pass=qual quantizer=20 tune=zerolatency !"
////          "rtph264pay name=pay0 pt=96 t. ! "
////          "queue ! d3dvideosink )");

////      /* notify when our media is ready, This is called whenever someone asks for
////       * the media and a new pipeline with our appsrc is created */
////      g_signal_connect (factory, "media-constructed", (GCallback) media_constructed,
////          NULL);

////      /* attach the test factory to the /test url */
////      gst_rtsp_mount_points_add_factory (mounts, "/test", factory);

////      /* don't need the ref to the mounts anymore */
////      g_object_unref (mounts);

////      /* attach the server to the default maincontext */
////      gst_rtsp_server_attach (server, NULL);

////      /* start serving */
////      g_print ("stream ready at rtsp://127.0.0.1:8554/test\n");
////      g_main_loop_run (loop);











////    CustomData data;
////    GstRTSPServer *server;
////    GstRTSPMountPoints *mounts;
////    GstRTSPMediaFactory *factory;

////    gst_init(NULL, NULL);

////    loop = g_main_loop_new(NULL, FALSE);

////    /* create a server instance */
////    server = gst_rtsp_server_new();

////    /* get the mount points for this server, every server has a default object
////     * that be used to map uri mount points to media factories */
////    mounts = gst_rtsp_server_get_mount_points(server);

////    /* make a media factory for a test stream. The default media factory can use
////     * gst-launch syntax to create pipelines.
////     * any launch line works as long as it contains elements named pay%d. Each
////     * element with pay%d names will be a stream */
////    factory = gst_rtsp_media_factory_new();


////    gst_rtsp_media_factory_set_launch(factory,
////        "( ksvideosrc device-index=0  ! video/x-raw, format=(string)I420, width=(int)1280, height=(int)720, framerate=(fraction)30/1 ! videoconvert ! x264enc pass=qual quantizer=20 tune=zerolatency ! rtph264pay name=pay0 pt=96 )");  //640x480 , 800x600, 1024x768    //  ! videoconvert ! x264enc ! rtph264pay

////    gst_rtsp_media_factory_set_shared(factory, TRUE);

////    /* attach the test factory to the /test url */
////    gst_rtsp_mount_points_add_factory(mounts, "/test", factory);

////    /* don't need the ref to the mapper anymore */
////    g_object_unref(mounts);

////    /* attach the server to the default maincontext */
////    gst_rtsp_server_attach(server, NULL);

////    /* start serving */
////    g_print("stream ready at rtsp://127.0.0.1:8554/test\n");
////    g_main_loop_run(loop);



//    ////-----------------------------------------------------------------------------------------------------------------------------------------

//    //    data.pipeline = gst_pipeline_new ("xvoverlay");
//    //    data.source = gst_element_factory_make ("videotestsrc", "ksvideosrc");
//    //    data.tee = gst_element_factory_make ("tee", "tee");
//    //    data.overlay_queue=gst_element_factory_make ("queue", "overlay_queue");
//    //    data.sink = gst_element_factory_make ("d3dvideosink", "d3dvideosink");
//    //    data.rtsp_queue = gst_element_factory_make ("queue", "rtsp_queue");
//    //    data.appsink = gst_element_factory_make ("appsink", "appsink");

//    //    if (!data.pipeline || !data.source || !data.tee || !data.overlay_queue || !data.sink ||
//    //          !data.rtsp_queue || !data.appsink ) {
//    //        g_printerr ("Not all elements could be created.\n");
//    //      }

//    //    gst_bin_add_many (GST_BIN (data.pipeline), data.source, data.tee, data.overlay_queue, data.sink, data.rtsp_queue, data.appsink, NULL);
//    //    if (gst_element_link_many (data.source, data.tee, NULL) != TRUE ||
//    //          gst_element_link_many (data.overlay_queue, data.sink, NULL) != TRUE ||
//    //          gst_element_link_many (data.rtsp_queue, data.appsink , NULL) != TRUE) {
//    //        g_printerr ("Elements could not be linked.\n");
//    //        gst_object_unref (data.pipeline);
//    //      }



//    //    /* Manually link the Tee, which has "Request" pads */
//    //      tee_overlay_pad = gst_element_get_request_pad (data.tee, "src_%u");
//    //      g_print ("Obtained request pad %s for audio branch.\n", gst_pad_get_name (tee_overlay_pad));
//    //      queue_overlay_pad = gst_element_get_static_pad (data.overlay_queue, "sink");
//    //      tee_rtsp_pad = gst_element_get_request_pad (data.tee, "src_%u");
//    //      g_print ("Obtained request pad %s for video branch.\n", gst_pad_get_name (tee_rtsp_pad));
//    //      queue_rtsp_pad = gst_element_get_static_pad (data.rtsp_queue, "sink");
//    //      if (gst_pad_link (tee_overlay_pad, queue_overlay_pad) != GST_PAD_LINK_OK ||
//    //          gst_pad_link (tee_rtsp_pad, queue_rtsp_pad) != GST_PAD_LINK_OK) {
//    //        g_printerr ("Tee could not be linked.\n");
//    //        gst_object_unref(data.pipeline);
//    //      }
//    //      gst_object_unref (queue_overlay_pad);
//    //      gst_object_unref (queue_rtsp_pad);

//    //      /* Start playing the pipeline */
//    //      gst_element_set_state (data.pipeline, GST_STATE_PLAYING);

//    //      /* Wait until error or EOS */
//    //      bus = gst_element_get_bus (data.pipeline);
//    //      msg = gst_bus_timed_pop_filtered (bus, GST_CLOCK_TIME_NONE, GstMessageType(GST_MESSAGE_ERROR | GST_MESSAGE_EOS));

//    //      /* Release the request pads from the Tee, and unref them */
//    //      gst_element_release_request_pad (data.tee, tee_rtsp_pad);
//    //      gst_element_release_request_pad (data.tee, tee_overlay_pad);
//    //      gst_object_unref (tee_rtsp_pad);
//    //      gst_object_unref (tee_overlay_pad);

//    ////---------------------------------------------------------------------------------------------------------------------------------------------------

//}

////остановить стрим
//void rtsp_stop()
//{
//    g_main_loop_quit(loop);
//}

////возобновить стрим
//void rtsp_play()
//{
//    g_main_loop_run(loop);
//}


