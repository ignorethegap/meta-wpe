QT5WEBKIT_FEATURES ??= '\
               ${@bb.utils.contains('PACKAGECONFIG', 'gstreamer','gstreamer1', '', d)} \
               dxdrm-eme \
'

QT5WEBKIT_CONFIG += '\
   ${@bb.utils.contains('QT5WEBKIT_FEATURES', 'gstreamer1', 'WEBKIT_CONFIG+=video',         '', d)} \   
   ${@bb.utils.contains('QT5WEBKIT_FEATURES', 'gstreamer1', 'WEBKIT_CONFIG+=use_gstreamer', '', d)} \ 
   ${@bb.utils.contains('QT5WEBKIT_FEATURES', 'gstreamer1', 'WEBKIT_CONFIG+=media_source',  '', d)} \ 
   ${@bb.utils.contains('QT5WEBKIT_FEATURES', 'gstreamer1', 'WEBKIT_CONFIG+=web_audio',     '', d)} \ 
   \
   ${@bb.utils.contains('QT5WEBKIT_FEATURES', 'dxdrm-eme',  'WEBKIT_CONFIG+=use_dxdrm',     '', d)} \ 
'

DEPENDS += '\
   ${@bb.utils.contains('QT5WEBKIT_FEATURES', 'gstreamer1', 'gstreamer1.0',                  '', d)} \ 
   ${@bb.utils.contains('QT5WEBKIT_FEATURES', 'gstreamer1', 'gstreamer1.0-plugins-base',     '', d)} \ 
   ${@bb.utils.contains('QT5WEBKIT_FEATURES', 'gstreamer1', 'gstreamer1.0-plugins-good',     '', d)} \    
   ${@bb.utils.contains('QT5WEBKIT_FEATURES', 'gstreamer1', 'gstreamer1.0-plugins-bad',      '', d)} \ 
   \
   ${@bb.utils.contains('QT5WEBKIT_FEATURES', 'dxdrm-eme',  'dxdrm',                         '', d)} \
'

QT5WEBKIT_EXTRA_LIBRARIES += '\
   ${@bb.utils.contains('QT5WEBKIT_FEATURES', 'dxdrm-eme',  'LIBS+=-lDxDrm',                 '', d)} \
'