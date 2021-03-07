package io.opentimeline.adapters;

/**
 * Each adapter is to be added as an annotation to the AdapterManifest. The adapter's class needs to be created
 * directly or in a package under io.opentimeline.adapters, and the class name
 * along with the package under io.opentimeline.adapters needs to be specified in <em>classname</em>.
 * <em>suffixes</em> are the file types supported by the adapter.
 */
@Adapter(name = "OTIO_JSON", classname = "OTIO_JSON", suffixes = {"otio"})
//@Adapter(name = "FCP_XML", classname = "FCP_XML", suffixes = {"xml"})
public class AdapterManifest {

    public static Adapter[] getAdaptersList() {
        Adapters adaptersAnnotation = AdapterManifest.class.getAnnotation(Adapters.class);
        return adaptersAnnotation.value();
    }

}
