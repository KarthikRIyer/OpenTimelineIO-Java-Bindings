package io.opentimeline;

import io.opentimeline.opentime.RationalTime;
import io.opentimeline.opentime.TimeRange;
import io.opentimeline.opentimelineio.Clip;
import io.opentimeline.opentimelineio.ExternalReference;
import org.junit.jupiter.api.Test;

public class AdapterTest {

    @Test
    public void testOTIOAdapter() {
        String name = "test";
        RationalTime rt = new RationalTime(5, 24);
        TimeRange tr = new TimeRange(rt, rt);
        ExternalReference mr = new ExternalReference.ExternalReferenceBuilder()
                .setTargetURL("/var/tmp/test.mov")
                .setAvailableRange(new TimeRange(rt, new RationalTime(10, 24)))
                .build();
        Clip clip = new Clip.ClipBuilder()
                .setName(name)
                .setMediaReference(mr)
                .setSourceRange(tr)
                .build();
        try {
            boolean result = Adapters.writeToFile(clip, "/home/karthik/clip.otio");
//            SerializableObject serializableObject = Adapters.readFromFile("/home/karthik/clip.otio");
//            Adapters.writeToFile(serializableObject, "/home/karthik/clip2.otio");
        } catch (Exception e) {
            e.printStackTrace();
        }
        try {
            mr.close();
            clip.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

}
