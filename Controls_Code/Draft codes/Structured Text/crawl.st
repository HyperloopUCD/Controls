PROGRAM Crawl
    VAR
        curr_pod_distance: INT;
        end_distance: INT;
        crawl_power: INT;
        buffer_distance: INT;
    END_VAR
    FUNCTION SlowCral
        VAR_INPUT
            crawl_pw: INT;
        END_VAR
        PWMCONTROL(crawl_pw);
    END_FUNCTION
    end_distance = GETENDDISTANCE();
    curr_pod_distance = GETPODPOSITION();
    IF curr_pod_distance < (end_distance - buffer_distance) THEN
        crawl_power := GETCRAWLSPEED();
    ELSE THEN
        crawl_power :=  0;
    END_IF
    SlowCral(crawl_power);
END_PROGRAM