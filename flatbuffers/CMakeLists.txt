add_custom_command(
    OUTPUT fbs/fbs.stamp
    DEPENDS /root/quantra/flatbuffers/fbs/*.fbs
    COMMAND flatc --cpp -o /root/quantra/flatbuffers/cpp  /root/quantra/flatbuffers/fbs/*.fbs
    COMMAND flatc --python -o /root/quantra/flatbuffers/python  /root/quantra/flatbuffers/fbs/*.fbs
    )

add_custom_target(
        fbs ALL
        DEPENDS fbs/fbs.stamp
    )